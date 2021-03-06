$NetBSD$

--- chrome/browser/tracing/crash_service_uploader.cc.orig	2016-11-10 20:02:11.000000000 +0000
+++ chrome/browser/tracing/crash_service_uploader.cc
@@ -155,6 +155,10 @@ void TraceCrashServiceUploader::DoUpload
   const char product[] = "Chrome_Android";
 #elif defined(OS_CHROMEOS)
   const char product[] = "Chrome_ChromeOS";
+#elif defined(OS_FREEBSD)
+  const char product[] = "Chrome_FreeBSD";
+#elif defined(OS_NETBSD)
+  const char product[] = "Chrome_NetBSD";
 #else
 #error Platform not supported.
 #endif
