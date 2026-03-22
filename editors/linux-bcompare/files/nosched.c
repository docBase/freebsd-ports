#define _GNU_SOURCE

#include <pthread.h>

/* Stub out pthread_attr_setinheritsched to prevent ENOSYS crashes
 * on FreeBSD's Linux compatibility layer.
 *
 * Original _dl_sym approach by shkhln and aragats (FreeBSD forums)
 * broke with glibc 2.34+ (Rocky Linux 9) which hid _dl_sym.
 * Direct override is simpler and sufficient since we only need to
 * intercept this one function via LD_PRELOAD.
 */

int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched) {
  (void)attr;
  (void)inheritsched;
  return 0;
}
