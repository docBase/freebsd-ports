# Beyond Compare 5.2.0 — Qt6 on FreeBSD Linuxulator: Status

**Date**: 2026-03-22
**Status**: BLOCKED — runtime hang, rolled back to 5.1.0
**Branch**: `integration` (commits 6626a86628 through 8af9f695db)

## Summary

Beyond Compare 5.2.0 switched from Qt5 to Qt6. Qt6 is not available in
FreeBSD's `linux-rl9` compatibility layer, so Qt6 runtime libraries were
bundled from EPEL/Rocky Linux 9 RPMs. The port builds and stages
successfully, but the application hangs at startup due to a SIGBUS spin
loop in the main thread.

## What Was Done

### Build Fixes (all working)

1. **Qt6 runtime bundling from EPEL RPMs**
   - Fetches 4 additional RPMs: qt6-qtbase, qt6-qtbase-gui, libb2, double-conversion
   - Extracts in `post-extract` via `rpm2cpio`
   - Bundles: libQt6Core.so.6, libQt6DBus.so.6, libQt6Gui.so.6,
     libQt6PrintSupport.so.6, libQt6Widgets.so.6, libQt6XcbQpa.so.6,
     libdouble-conversion.so.3, libb2.so.1
   - Platform plugin: platforms/libqxcb.so
   - GL integration: xcbglintegrations/libqxcb-{egl,glx}-integration.so

2. **nosched.c rewrite for glibc 2.34+**
   - Original used `_dl_sym` (glibc-internal, hidden in 2.34+)
   - Rewrote to directly override `pthread_attr_setinheritsched`
   - Returns 0 (success) to prevent ENOSYS crashes on linuxulator

3. **libgomp.so.1 bundling**
   - Copied from linuxulator's devtools (`/compat/linux/usr/lib64/libgomp.so.1`)
   - Avoids making devtools (3000+ files) a runtime dependency

4. **EXTRACT_DEPENDS for rpm2cpio**
   - Changed from BUILD_DEPENDS to EXTRACT_DEPENDS
   - Used full path `${LOCALBASE}/bin/rpm2cpio` (not in poudriere extract PATH)

5. **USE_LINUX changed from gtk3 to dbuslibs**
   - Qt6 does not depend on GTK3

### Runtime Fixes Attempted

6. **QT_XCB_GL_INTEGRATION=none**
   - Disables XCB GL integration (Linux mesa doesn't work on linuxulator)
   - Prevents one source of busy-loop

7. **QT_NO_GLIB=1**
   - Switches Qt6 from GLib event dispatcher to Unix dispatcher
   - GLib's eventfd/poll interaction causes busy-loop on linuxulator
   - Confirmed working: debug output shows "using unix dispatcher"

8. **QT_PLUGIN_PATH set to bundled lib dir**
   - Ensures Qt6 finds platform plugins in the bundle

### The Blocker: SIGBUS Spin Loop

After all the above fixes, the application still hangs. `truss` revealed
the main thread (PID 24569) is trapped in a tight SIGBUS loop:

```
SIGNAL 10 (SIGBUS) code=12 trapno=12 addr=0x1ccc5d4
linux_rt_sigprocmask(0x1,0x7fffffffa7d0,0x0,0x8) = 0 (0x0)
linux_rt_sigreturn(0x50)                  EJUSTRETURN
[repeats thousands of times per second]
```

**Analysis:**
- `addr=0x1ccc5d4` is in the data/BSS segment (very low address)
- `trapno=12` is x86-64 #SS (Stack Segment Fault) — unusual for data addr
- The app has a signal handler that returns, but the same instruction
  faults again immediately → infinite spin
- Likely cause: `mprotect`-based safepoints used by Free Pascal's runtime
  or a memory-mapped region the linuxulator can't properly serve
- An enhanced nosched.so with a SIGBUS handler that calls `mprotect()` to
  make the faulting page readable was prepared but NOT tested

**Diagnostic commands not yet run:**
```bash
PID=$(pgrep -f BCompare | head -1)
procstat -v $PID           # FreeBSD memory map — what's at 0x1ccc5d4?
cat /compat/linux/proc/$PID/maps   # Linux-side memory map
procstat -i $PID           # Signal dispositions
```

## Files Modified (5.2.0 state, now rolled back)

### Makefile
- `DISTVERSION=5.2.0`, `DISTVERSIONSUFFIX=.31950`
- `MASTER_SITES` included EPEL/RL9 RPM URLs (qt6base, qt6gui, libb2, dblconv groups)
- `DISTFILES` listed 5 files (main RPM + 4 Qt6 dep RPMs)
- `EXTRACT_DEPENDS=rpm2cpio:archivers/rpm2cpio`
- `USE_LINUX=base:run dbuslibs:run devtools:build xorglibs:run`
- `LIB_FILES` included Qt6 libs, nosched.so, libb2, libdouble-conversion
- `EXTRA_PATCHES=${PATCHDIR}/extra-patch-usr_bin_bcompare_amd64`
- `post-extract:` target to extract Qt6 from RPMs
- `pre-install:` compiles nosched.c with linuxulator gcc
- `do-install:` copies libgomp.so.1, platform plugins, xcbglintegrations

### files/nosched.c
```c
#define _GNU_SOURCE
#include <pthread.h>

int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched) {
  (void)attr;
  (void)inheritsched;
  return 0;
}
```
An enhanced version with SIGBUS handler (mprotect fix) was also prepared
but not tested at runtime.

### files/extra-patch-usr_bin_bcompare_amd64
Wrapper script patch adding:
- `LINUXULATOR_LIB=/compat/linux/usr/lib64`
- `BC_LIB=/usr/local/lib/beyondcompare`
- `_LD_PRELOAD="$BC_LIB/nosched.so"`
- `QT_NO_GLIB=1`
- `QT_XCB_GL_INTEGRATION=none`
- `QT_PLUGIN_PATH="$BC_LIB"`
- `LD_LIBRARY_PATH` includes `$LINUXULATOR_LIB`
- Exec line: `/usr/bin/env bash -c "exec -a $0 /usr/bin/env LD_PRELOAD=$_LD_PRELOAD $EXEC $ARGS" $0`
- Cleanup: removes bash.core and pgrep.core

### pkg-plist additions (over 5.1.0)
- `lib/beyondcompare/libQt6Core.so.6`
- `lib/beyondcompare/libQt6DBus.so.6`
- `lib/beyondcompare/libQt6Gui.so.6`
- `lib/beyondcompare/libQt6PrintSupport.so.6`
- `lib/beyondcompare/libQt6Widgets.so.6`
- `lib/beyondcompare/libQt6XcbQpa.so.6`
- `lib/beyondcompare/libb2.so.1`
- `lib/beyondcompare/libdouble-conversion.so.3`
- `lib/beyondcompare/libgomp.so.1`
- `lib/beyondcompare/platforms/libqxcb.so`
- `lib/beyondcompare/xcbglintegrations/libqxcb-egl-integration.so`
- `lib/beyondcompare/xcbglintegrations/libqxcb-glx-integration.so`

### distinfo
```
TIMESTAMP = 1742567476
SHA256 (bcompare-5.2.0.31950.x86_64.rpm) = f8f1d0...
SIZE (bcompare-5.2.0.31950.x86_64.rpm) = 14476556
[+ 4 Qt6 RPM checksums]
```

## Git Commits (integration branch)

```
8af9f695db  set QT_XCB_GL_INTEGRATION=none and QT_PLUGIN_PATH in wrapper
7f85408351  add XCB GL integration plugins
d7ae491e21  bundle Qt6 XCB platform plugin
c20b954eb6  fix nosched.so for glibc 2.34+ (RL9)
7048f04cab  bundle libgomp.so.1 for runtime
6850685230  fix rpm2cpio path for poudriere, use EXTRACT_DEPENDS
7914eb4436  bundle Qt6 runtime from EPEL RPMs
6626a86628  editors/linux-bcompare: update to 5.2.0 (WIP)
```

## Next Steps to Resume 5.2.0

1. **Diagnose SIGBUS root cause**: Run `procstat -v` and `/proc/PID/maps`
   to determine what memory region contains `0x1ccc5d4`
2. **Test enhanced nosched.so**: The SIGBUS handler version (mprotect fix)
   was written but never tested at runtime
3. **If mprotect doesn't help**: Use `truss -o /tmp/bcompare.truss -f`
   to capture full syscall trace from startup
4. **Consider FPC runtime flags**: Free Pascal may have env vars to disable
   signal-based safepoints or memory protection schemes
5. **Check FreeBSD PR database**: Search for linuxulator SIGBUS issues with
   Qt6 or FPC applications
6. **Once window appears**: Restore `> /dev/null 2>&1` redirect in wrapper,
   rebuild in poudriere, final test

## References

- FreeBSD forums: nosched.c origin (shkhln, aragats)
- glibc 2.34 changelog: `_dl_sym` hidden
- Qt6 env vars: https://doc.qt.io/qt-6/qguiapplication.html
- EPEL 9 packages: https://dl.fedoraproject.org/pub/epel/9/Everything/x86_64/
