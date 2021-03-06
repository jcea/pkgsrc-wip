$NetBSD$

--- media/filters/decrypting_audio_decoder.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ media/filters/decrypting_audio_decoder.cc
@@ -29,7 +29,7 @@ static inline bool IsOutOfSync(const bas
   // Out of sync of 100ms would be pretty noticeable and we should keep any
   // drift below that.
   const int64_t kOutOfSyncThresholdInMilliseconds = 100;
-  return std::abs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
+  return std::labs(timestamp_1.InMilliseconds() - timestamp_2.InMilliseconds()) >
          kOutOfSyncThresholdInMilliseconds;
 }
 
