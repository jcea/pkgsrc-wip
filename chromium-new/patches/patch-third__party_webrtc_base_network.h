$NetBSD$

--- third_party/webrtc/base/network.h.orig	2016-11-10 20:03:05.000000000 +0000
+++ third_party/webrtc/base/network.h
@@ -23,6 +23,10 @@
 #include "webrtc/base/messagehandler.h"
 #include "webrtc/base/sigslot.h"
 
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
+#endif
+
 #if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
