$NetBSD$

--- third_party/libyuv/include/libyuv/row.h.orig	2016-11-10 20:03:02.000000000 +0000
+++ third_party/libyuv/include/libyuv/row.h
@@ -167,10 +167,14 @@ extern "C" {
 #define HAS_ARGBSHADEROW_SSE2
 #define HAS_ARGBSUBTRACTROW_SSE2
 #define HAS_ARGBUNATTENUATEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_SSSE3
+#endif
 #define HAS_COMPUTECUMULATIVESUMROW_SSE2
 #define HAS_CUMULATIVESUMTOAVERAGEROW_SSE2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_SSSE3
+#endif
 #define HAS_RGBCOLORTABLEROW_X86
 #define HAS_SOBELROW_SSE2
 #define HAS_SOBELTOPLANEROW_SSE2
@@ -180,8 +184,7 @@ extern "C" {
 
 // The following functions fail on gcc/clang 32 bit with fpic and framepointer.
 // caveat: clangcl uses row_win.cc which works.
-#if defined(NDEBUG) || !(defined(_DEBUG) && defined(__i386__)) || \
-    !defined(__i386__) || defined(_MSC_VER)
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on x86 debug
 // https://code.google.com/p/libyuv/issues/detail?id=524
 #define HAS_I411TOARGBROW_SSSE3
@@ -209,7 +212,7 @@ extern "C" {
 #define HAS_COPYROW_AVX
 #define HAS_H422TOARGBROW_AVX2
 #define HAS_I400TOARGBROW_AVX2
-#if !(defined(_DEBUG) && defined(__i386__))
+#if !(defined(__i386__) && defined(__GNUC__))
 // TODO(fbarchard): fix build error on android_full_debug=1
 // https://code.google.com/p/libyuv/issues/detail?id=517
 #define HAS_I422ALPHATOARGBROW_AVX2
@@ -222,7 +225,9 @@ extern "C" {
 #define HAS_I422TORGB565ROW_AVX2
 #define HAS_I422TORGBAROW_AVX2
 #define HAS_I444TOARGBROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_INTERPOLATEROW_AVX2
+#endif
 #define HAS_J422TOARGBROW_AVX2
 #define HAS_MERGEUVROW_AVX2
 #define HAS_MIRRORROW_AVX2
@@ -245,8 +250,10 @@ extern "C" {
 #define HAS_ARGBMULTIPLYROW_AVX2
 #define HAS_ARGBSUBTRACTROW_AVX2
 #define HAS_ARGBUNATTENUATEROW_AVX2
+#if !(defined(__i386__) && defined(__GNUC__))
 #define HAS_BLENDPLANEROW_AVX2
 #endif
+#endif
 
 // The following are available for AVX2 Visual C and clangcl 32 bit:
 // TODO(fbarchard): Port to gcc.
