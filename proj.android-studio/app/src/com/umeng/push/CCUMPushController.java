package com.umeng.push;

import java.util.List;

import android.util.Log;
import android.widget.Toast;
import com.umeng.message.MsgConstant;
import com.umeng.message.PushAgent;
import com.umeng.message.UTrack;
import com.umeng.message.common.UmengMessageDeviceConfig;
import com.umeng.message.common.inter.ITagManager;
import com.umeng.message.tag.TagManager;

public class CCUMPushController {

    private static final String TAG = CCUMPushController.class.getSimpleName();
    private PushAgent mPushAgent;

    public void addTag(String tag) {
        mPushAgent.getTagManager().addTags(new TagManager.TCallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final ITagManager.Result result) {
                if (isSuccess) {
                    successCallback.invoke(0,resultToMap(result));
                } else {
                    successCallback.invoke(-1,resultToMap(result));
                }
            }
        }, tag);
    }

    public void deleteTag(String tag) {
        mPushAgent.getTagManager().deleteTags(new TagManager.TCallBack() {
            @Override
            public void onMessage(boolean isSuccess, final ITagManager.Result result) {
                Log.i(TAG, "isSuccess:" + isSuccess);
                if (isSuccess) {
                    successCallback.invoke(0,resultToMap(result));
                } else {
                    successCallback.invoke(-1,resultToMap(result));
                }
            }
        }, tag);
    }

    public void listTag() {
        mPushAgent.getTagManager().getTags(new TagManager.TagListCallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final List<String> result) {
                mSDKHandler.post(new Runnable() {
                    @Override
                    public void run() {
                        if (isSuccess) {
                            if (result != null) {

                                successCallback.invoke(0,resultToList(result));
                            } else {
                                successCallback.invoke(-1,resultToList(result));
                            }
                        } else {
                            successCallback.invoke(-2,resultToList(result));
                        }

                    }
                });

            }
        });
    }

    public void addAlias(String alias, String aliasType) {
        mPushAgent.addAlias(alias, aliasType, new UTrack.ICallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final String message) {
                Log.i(TAG, "isSuccess:" + isSuccess + "," + message);

                Log.e("xxxxxx","isuccess"+isSuccess);
                if (isSuccess) {
                    successCallback.invoke(0,message);
                } else {
                    successCallback.invoke(-1,"");
                }


            }
        });
    }

    public void addAliasType() {
        Toast.makeText(ma,"function will come soon",Toast.LENGTH_LONG);
    }

    public void setAlias(String exclusiveAlias, String aliasType) {
        mPushAgent.setAlias(exclusiveAlias, aliasType, new UTrack.ICallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final String message) {

                Log.i(TAG, "isSuccess:" + isSuccess + "," + message);
                if (Boolean.TRUE.equals(isSuccess)) {
                    successCallback.invoke(0,message);
                }else {
                    successCallback.invoke(-1,"");
                }



            }
        });
    }

    public void deleteAlias(String alias, String aliasType) {
        mPushAgent.deleteAlias(alias, aliasType, new UTrack.ICallBack() {
            @Override
            public void onMessage(boolean isSuccess, String s) {
                if (Boolean.TRUE.equals(isSuccess)) {
                    successCallback.invoke(0,s);
                }else {
                    successCallback.invoke(-1,"");
                }
            }
        });
    }

    public void appInfo() {
        String pkgName = context.getPackageName();
        String info = String.format("DeviceToken:%s\n" + "SdkVersion:%s\nAppVersionCode:%s\nAppVersionName:%s",
            mPushAgent.getRegistrationId(), MsgConstant.SDK_VERSION,
            UmengMessageDeviceConfig.getAppVersionCode(context), UmengMessageDeviceConfig.getAppVersionName(context));
        successCallback.invoke("应用包名:" + pkgName + "\n" + info);
    }
}
