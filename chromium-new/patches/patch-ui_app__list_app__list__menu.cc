$NetBSD$

--- ui/app_list/app_list_menu.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/app_list/app_list_menu.cc
@@ -30,7 +30,7 @@ void AppListMenu::InitMenu() {
   // only 1 user.
   if (users_.size() > 1) {
     for (size_t i = 0; i < users_.size(); ++i) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
       menu_model_.AddItem(SELECT_PROFILE + i, users_[i].name);
       int menu_index = menu_model_.GetIndexOfCommandId(SELECT_PROFILE + i);
       menu_model_.SetSublabel(menu_index, users_[i].email);
