$NetBSD$

--- content/common/set_process_title_linux.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/common/set_process_title_linux.cc
@@ -49,6 +49,8 @@
 extern char** environ;
 
 static char** g_main_argv = NULL;
+
+#if !defined(OS_FREEBSD)
 static char* g_orig_argv0 = NULL;
 
 void setproctitle(const char* fmt, ...) {
@@ -101,6 +103,7 @@ void setproctitle(const char* fmt, ...) 
   va_end(ap);
   g_main_argv[1] = NULL;
 }
+#endif
 
 // A version of this built into glibc would not need this function, since
 // it could stash the argv pointer in __libc_start_main(). But we need it.
