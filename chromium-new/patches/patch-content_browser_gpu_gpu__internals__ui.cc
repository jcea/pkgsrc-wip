$NetBSD$

--- content/browser/gpu/gpu_internals_ui.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/gpu/gpu_internals_ui.cc
@@ -42,7 +42,7 @@
 #include "third_party/skia/include/core/SkMilestone.h"
 #include "ui/gl/gpu_switching_manager.h"
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include <X11/Xlib.h>
 #endif
 #if defined(OS_WIN)
@@ -50,7 +50,7 @@
 #include "ui/gfx/win/physical_size.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"       // nogncheck
 #include "ui/gfx/x/x11_atom_cache.h"  // nogncheck
 #endif
@@ -204,7 +204,7 @@ base::DictionaryValue* GpuInfoAsDictiona
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {
