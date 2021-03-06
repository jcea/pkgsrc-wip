$NetBSD$

--- net/base/network_interfaces_posix.cc.orig	2016-11-10 20:02:16.000000000 +0000
+++ net/base/network_interfaces_posix.cc
@@ -20,6 +20,7 @@ namespace net {
 #if !defined(OS_NACL)
 namespace internal {
 
+#if !defined(OS_BSD)
 // The application layer can pass |policy| defined in net_util.h to
 // request filtering out certain type of interfaces.
 bool ShouldIgnoreInterface(const std::string& name, int policy) {
@@ -33,6 +34,7 @@ bool ShouldIgnoreInterface(const std::st
 
   return false;
 }
+#endif
 
 // Check if the address is unspecified (i.e. made of zeroes) or loopback.
 bool IsLoopbackOrUnspecifiedAddress(const sockaddr* addr) {
