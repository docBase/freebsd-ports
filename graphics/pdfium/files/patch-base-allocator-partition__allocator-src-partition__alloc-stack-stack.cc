--- base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc.orig	2025-01-01 00:00:00 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc
@@ -16,6 +16,9 @@
 #include <windows.h>
 #else
 #include <pthread.h>
+#if defined(__FreeBSD__)
+#include <pthread_np.h>
+#endif
 #endif

 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
@@ -54,7 +57,12 @@

 void* GetStackTop() {
   pthread_attr_t attr;
+#if defined(__FreeBSD__)
+  pthread_attr_init(&attr);
+  int error = pthread_attr_get_np(pthread_self(), &attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (!error) {
     void* base;
     size_t size;
