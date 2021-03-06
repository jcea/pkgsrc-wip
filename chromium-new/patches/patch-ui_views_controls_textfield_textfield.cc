$NetBSD$

--- ui/views/controls/textfield/textfield.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/views/controls/textfield/textfield.cc
@@ -51,7 +51,7 @@
 #include "ui/base/win/osk_display_manager.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -156,14 +156,14 @@ ui::TextEditCommand GetCommandForKeyEven
     case ui::VKEY_BACK:
       if (!control)
         return ui::TextEditCommand::DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
@@ -596,7 +596,7 @@ bool Textfield::OnMousePressed(const ui:
       OnAfterUserAction();
     }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     if (event.IsOnlyMiddleMouseButton()) {
       if (GetRenderText()->IsPointInSelection(event.location())) {
         OnBeforeUserAction();
@@ -665,7 +665,7 @@ bool Textfield::OnKeyPressed(const ui::K
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -805,7 +805,7 @@ void Textfield::AboutToRequestFocusFromT
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1065,7 +1065,7 @@ void Textfield::WriteDragDataForView(Vie
   std::unique_ptr<gfx::Canvas> canvas(
       GetCanvasForDragImage(GetWidget(), label.size()));
   label.SetEnabledColor(GetTextColor());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Desktop Linux Aura does not yet support transparency in drag images.
   canvas->DrawColor(GetBackgroundColor());
 #endif
@@ -2004,7 +2004,7 @@ void Textfield::CreateTouchSelectionCont
 }
 
 void Textfield::UpdateSelectionClipboard() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (performing_user_action_ && HasSelection()) {
     ui::ScopedClipboardWriter(
         ui::CLIPBOARD_TYPE_SELECTION).WriteText(GetSelectedText());
