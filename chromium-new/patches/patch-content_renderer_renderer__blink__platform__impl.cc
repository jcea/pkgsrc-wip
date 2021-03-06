$NetBSD$

--- content/renderer/renderer_blink_platform_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.cc
@@ -114,7 +114,7 @@
 
 #if defined(OS_POSIX)
 #include "base/file_descriptor_posix.h"
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #include <map>
 #include <string>
 
@@ -219,7 +219,7 @@ class RendererBlinkPlatformImpl::FileUti
   scoped_refptr<ThreadSafeSender> thread_safe_sender_;
 };
 
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
 class RendererBlinkPlatformImpl::SandboxSupport
     : public blink::WebSandboxSupport {
  public:
@@ -266,7 +266,7 @@ RendererBlinkPlatformImpl::RendererBlink
       renderer_scheduler_(renderer_scheduler),
       blink_interface_provider_(
           new BlinkInterfaceProviderImpl(remote_interfaces)) {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   if (g_sandbox_enabled && sandboxEnabled()) {
     sandbox_support_.reset(new RendererBlinkPlatformImpl::SandboxSupport);
   } else {
@@ -297,7 +297,7 @@ RendererBlinkPlatformImpl::~RendererBlin
 }
 
 void RendererBlinkPlatformImpl::Shutdown() {
-#if !defined(OS_ANDROID) && !defined(OS_WIN)
+#if !defined(OS_ANDROID) && !defined(OS_WIN) && !defined(OS_BSD)
   // SandboxSupport contains a map of WebFontFamily objects, which hold
   // WebCStrings, which become invalidated when blink is shut down. Hence, we
   // need to clear that map now, just before blink::shutdown() is called.
@@ -349,7 +349,7 @@ blink::WebFileUtilities* RendererBlinkPl
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::sandboxSupport() {
-#if defined(OS_ANDROID) || defined(OS_WIN)
+#if defined(OS_ANDROID) || defined(OS_WIN) || defined(OS_BSD)
   // These platforms do not require sandbox support.
   return NULL;
 #else
@@ -602,7 +602,7 @@ bool RendererBlinkPlatformImpl::SandboxS
   return FontLoader::CGFontRefFromBuffer(font_data, font_data_size, out);
 }
 
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 
 void RendererBlinkPlatformImpl::SandboxSupport::getFallbackFontForCharacter(
     blink::WebUChar32 character,
