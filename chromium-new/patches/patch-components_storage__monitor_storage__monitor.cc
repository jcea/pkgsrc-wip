$NetBSD$

--- components/storage_monitor/storage_monitor.cc.orig	2016-11-10 20:02:13.000000000 +0000
+++ components/storage_monitor/storage_monitor.cc
@@ -85,6 +85,7 @@ std::vector<StorageInfo> StorageMonitor:
 
 void StorageMonitor::EnsureInitialized(base::Closure callback) {
   DCHECK(thread_checker_.CalledOnValidThread());
+//#if !defined(OS_BSD) //XXX(rene) why disabled?
   if (initialized_) {
     if (!callback.is_null())
       callback.Run();
@@ -100,6 +101,7 @@ void StorageMonitor::EnsureInitialized(b
 
   initializing_ = true;
   Init();
+//#endif
 }
 
 bool StorageMonitor::IsInitialized() const {
