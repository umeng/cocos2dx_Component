LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)

LOCAL_MODULE := libweibosdkcore
LOCAL_SRC_FILES := prebuild/armeabi/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcorev8
LOCAL_SRC_FILES := prebuild/arm64-v8a/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcorev7
LOCAL_SRC_FILES := prebuild/armeabi-v7a/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcoremips
LOCAL_SRC_FILES := prebuild/mips/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcoremips64
LOCAL_SRC_FILES := prebuild/mips64/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcorex86
LOCAL_SRC_FILES := prebuild/x86/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libweibosdkcorex64
LOCAL_SRC_FILES := prebuild/x86_64/libweibosdkcore.so
include $(PREBUILT_SHARED_LIBRARY)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../../Classes/push/PushScence.cpp \
                   ../../../Classes/analytics/AppScence.cpp \
                   ../../../Classes/analytics/GameScence.cpp \
                   ../../../Classes/analytics/AnalyticsHome.cpp \
                   ../../../Classes/share/Entrance.cpp \
                   ../../../Classes/share/GetScene.cpp \
                   ../../../Classes/share/ShareScene.cpp \
                   ../../../Classes/share/AuthScene.cpp \
                   ../../../Classes/AppDelegate.cpp \
                   ../../../Classes/share/CCUMSocialSDK.cpp \
                   ../../../Classes/push/CCUMPushSDK.cpp \
                   ../../../Classes/analytics/MobClickCpp.cpp \
                   ../../../Classes/HelloWorldScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes \
                    $(LOCAL_PATH)/../../../Classes/share \
                    $(LOCAL_PATH)/../../../Classes/push \
                    $(LOCAL_PATH)/../../../Classes/analytics \

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
