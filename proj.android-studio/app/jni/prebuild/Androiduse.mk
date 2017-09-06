LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcore
LOCAL_SRC_FILES := armeabi/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)