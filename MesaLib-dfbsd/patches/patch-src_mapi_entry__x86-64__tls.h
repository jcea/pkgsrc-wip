$NetBSD: patch-src_mapi_entry__x86-64__tls.h,v 1.2 2015/09/26 08:45:02 tnn Exp $

NetBSD only supports zero-initialized initial-exec tls variables in conjuction
with dlopen(3) at the moment.

Fix --enable-glx-tls with clang. From FreeBSD.

HACK: Renamed non-linking table_noop_array to locally created
netbsd_table_noop_array.

--- src/mapi/entry_x86-64_tls.h.orig	2016-11-10 22:05:17.000000000 +0000
+++ src/mapi/entry_x86-64_tls.h
@@ -41,10 +41,19 @@ __asm__(".text\n"
    ".balign 32\n"                                        \
    func ":"
 
+#if defined(__NetBSD__) && defined(GLX_USE_TLS)
 #define STUB_ASM_CODE(slot)                              \
    "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
    "movq %fs:(%rax), %r11\n\t"                           \
+   "testq %r11, %r11\n\t"                                \
+   "cmoveq netbsd_table_noop_array @GOTPCREL(%rip), %r11\n\t"    \
    "jmp *(8 * " slot ")(%r11)"
+#else
+#define STUB_ASM_CODE(slot)                              \
+   "movq " ENTRY_CURRENT_TABLE "@GOTTPOFF(%rip), %rax\n\t"  \
+   "movq %fs:(%rax), %r11\n\t"                           \
+   "jmp *(8 * " slot ")(%r11)"
+#endif
 
 #define MAPI_TMP_STUB_ASM_GCC
 #include "mapi_tmp.h"
