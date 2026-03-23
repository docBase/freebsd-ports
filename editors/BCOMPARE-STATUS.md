# Beyond Compare — FreeBSD Port Status

**Last updated**: 2026-03-24
**Branch**: `integration` (pushed to `mp` remote)
**Maintainer**: matias@pizarro.net

## Current State: editors/linux-bcompare (5.1.0 — READY TO SUBMIT)

### Status: COMPLETE — submission patch generated

The port has been upgraded from the old tree version to 5.1.0 (Qt5) with
the following improvements over what's currently in the ports tree:

1. **nosched.so injection via `patchelf --add-needed`** — LD_PRELOAD does
   NOT survive the FreeBSD-to-Linux exec transition through the linuxulator,
   so nosched.so is patched directly into the BCompare ELF as a dependency
2. **dlvsym-based nosched.c** — BCompare (Free Pascal) resolves
   `pthread_attr_setinheritsched` via `dlsym()` at runtime, so the interception
   must happen at the dlsym level using `dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.2.5")`
3. **SSH_AUTH_SOCK passthrough** — enables SFTP/SSH connections when ssh-agent
   is running
4. **KDE 6 session detection** — wrapper script updated for KDE_SESSION_VERSION=6
5. **linux:rl9 base** — migrated to Rocky Linux 9 compatibility layer

### Submission Artifact

- **Patch file**: `/tmp/linux-bcompare.patch` (852 lines)
- **Generated from**: `git diff main -- editors/linux-bcompare/`
- **Submit to**: FreeBSD Bugzilla as a ports update

### Files Changed (vs main)

| File | Change |
|------|--------|
| `Makefile` | Version 5.1.0.31016, added patchelf BUILD_DEPENDS, pre-install target, linux:rl9, USE_LINUX deps |
| `distinfo` | Updated checksums for 5.1.0 RPM |
| `files/nosched.c` | dlvsym-based dlsym interceptor (minor whitespace fix from main) |
| `files/patch-usr_bin_bcompare` | NEW — wrapper script with linuxulator paths, SSH_AUTH_SOCK, KDE6, LD_PRELOAD |
| `files/extra-patch-usr_bin_bcompare_i386` | REMOVED — no i386 support |
| `pkg-plist` | Updated for 5.1.0 Qt5 file list |

### Key Technical Details

- **nosched.c mechanism**: A direct `pthread_attr_setinheritsched` override
  does NOT work. BCompare uses `dlsym("pthread_attr_setinheritsched")` at
  runtime (Free Pascal pattern), so we must intercept `dlsym()` itself.
  The working nosched.c uses `dlvsym()` to bootstrap a pointer to the real
  `dlsym`, then returns a no-op stub when the target symbol is requested.

- **patchelf injection**: `patchelf --add-needed nosched.so` runs in
  `pre-install:` on the source binary (before `INSTALL_PROGRAM` copies it
  with mode 555). This makes nosched.so a direct ELF dependency, avoiding
  the LD_PRELOAD linuxulator limitation entirely.

- **Build/runtime deps**:
  - BUILD_DEPENDS: patchelf
  - USE_LINUX: base:run curl:run dbuslibs:run devtools:build freetype:run
    qtx11extras:run systemd-libs:run xcb-util:run xorglibs:run

### Git Commits (integration, oldest first)

```
979aaaf6e1  editors/linux-bcompare: roll back to 5.1.0 (Qt5)
576e03e769  editors/linux-bcompare: restore missing USE_LINUX runtime deps
55b1d1aa76  editors/linux-bcompare: restore dlvsym-based nosched.c, sync with bcompare5
da22981d6d  editors/linux-bcompare: use patchelf to inject nosched.so
ac2eb336fb  editors/linux-bcompare: add SSH_AUTH_SOCK passthrough for SFTP/SSH support
```

### Verification

- Builds in poudriere: YES
- Stages correctly: YES
- check-plist passes: YES
- Runs on FreeBSD with linuxulator: YES (confirmed by maintainer)

---

## Current State: editors/linux-bcompare5 (5.1.0 — WORKING)

### Status: COMPLETE — parallel port with PKGNAMESUFFIX=5

Identical to linux-bcompare but with `PKGNAMESUFFIX=5`, creating package
`linux-bcompare5`. Uses `CONFLICTS_INSTALL=linux-bcompare[0-9]*` to prevent
co-installation.

**Note**: linux-bcompare5 does NOT yet have the SSH_AUTH_SOCK passthrough
fix. Its `patch-usr_bin_bcompare` should be synced from linux-bcompare if
this port is to be maintained alongside it.

### Git Commits

```
9ad53acb15  editors/linux-bcompare5: restore known-working 5.1.0 port
4e001e7450  editors/linux-bcompare5: use patchelf to inject nosched.so
```

---

## Deferred: Beyond Compare 5.2.0 (Qt6 — BLOCKED)

See `editors/BCOMPARE-520-QT6-STATUS.md` for full details.

**Blocker**: SIGBUS spin loop at addr 0x1ccc5d4 (trapno=12, Stack Segment
Fault). Main thread trapped in infinite signal/return cycle. Likely caused
by Free Pascal runtime's mprotect-based safepoints or a memory region the
linuxulator cannot properly serve.

**Key difference**: 5.2.0 uses Qt6 (not available in linux-rl9 layer, must
be bundled from EPEL RPMs). The build and staging work; only runtime is
broken.

**Resume steps**: See BCOMPARE-520-QT6-STATUS.md § "Next Steps to Resume 5.2.0"

---

## Pending Actions

1. **Submit `editors/linux-bcompare`** — use `/tmp/linux-bcompare.patch`
   (or regenerate with `cd /usr/ports && git diff main -- editors/linux-bcompare/`)
2. **Sync SSH_AUTH_SOCK to linux-bcompare5** — copy the updated
   `patch-usr_bin_bcompare` from linux-bcompare
3. **Decide on linux-bcompare5** — is a separate suffixed port still needed,
   or is linux-bcompare sufficient?
4. **Investigate 5.2.0 SIGBUS** — when time permits, per the status doc

---

## Quick Reference

```bash
# Regenerate submission patch
cd /usr/ports && git diff main -- editors/linux-bcompare/ > /tmp/linux-bcompare.patch

# Build in poudriere
poudriere testport -j 150amd64 -p default editors/linux-bcompare

# Test manually
pkg install /path/to/linux-bcompare-5.1.0.31016.pkg
bcompare

# Check port quality
cd /usr/ports/editors/linux-bcompare
portfmt -i Makefile && portclippy Makefile && portlint -A
```
