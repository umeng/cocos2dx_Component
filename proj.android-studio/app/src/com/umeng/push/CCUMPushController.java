package com.umeng.push;

import java.util.List;

import android.app.Activity;
import android.util.Log;
import android.widget.Toast;
import com.umeng.message.MsgConstant;
import com.umeng.message.PushAgent;
import com.umeng.message.UTrack;
import com.umeng.message.common.UmengMessageDeviceConfig;
import com.umeng.message.common.inter.ITagManager;
import com.umeng.message.tag.TagManager;
import com.umeng.socialize.ShareAction;
import com.umeng.socialize.UMShareAPI;
import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

public class CCUMPushController {
    private final int SUCCESS = 0;
    private final int ERROR = -1;
    private static final String TAG = CCUMPushController.class.getSimpleName();
    private PushAgent mPushAgent;
    private native static void tagsCallback(int code,String[] key);
    private native static void aliasCallback(int code);
    private native static void remainCallback(int code,int remain);
    private static Cocos2dxActivity mActivity;
    public static void initSocialSDK(final Activity activity, String descriptor) {


        if (activity instanceof Cocos2dxActivity) {
            mActivity = (Cocos2dxActivity) activity;
        } else {
            throw new IllegalArgumentException(
                "initSocialSDK函数的activity参数必须设置为Cocos2dxActivity类型, 且不为null. ");
        }


    }
    public void addTag(String tag) {
        mPushAgent.getTagManager().addTags(new TagManager.TCallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final ITagManager.Result result) {
                if (isSuccess) {
                    remainCallback(SUCCESS,result.remain);
                } else {
                    remainCallback(ERROR,0);
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
                    remainCallback(SUCCESS,result.remain);
                } else {
                    remainCallback(ERROR,0);
                }
            }
        }, tag);
    }
    public static void runNativeCallback(Runnable runnable)
    {
        Cocos2dxGLSurfaceView.getInstance().queueEvent(runnable);
    }
    public void listTag() {
        mPushAgent.getTagManager().getTags(new TagManager.TagListCallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final List<String> result) {
                runNativeCallback(new Runnable() {
                    @Override
                    public void run() {
                        if (isSuccess) {
                            if (result != null) {
                                String [] r = (String[])result.toArray();
                               tagsCallback(SUCCESS,r);
                            } else {
                                tagsCallback(ERROR,null);
                            }
                        } else {
                            tagsCallback(ERROR,null);
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
                    aliasCallback(SUCCESS);
                } else {
                    aliasCallback(ERROR);
                }


            }
        });
    }

    public void addAliasType() {

    }

    public void setAlias(String exclusiveAlias, String aliasType) {
        mPushAgent.setAlias(exclusiveAlias, aliasType, new UTrack.ICallBack() {
            @Override
            public void onMessage(final boolean isSuccess, final String message) {

                Log.i(TAG, "isSuccess:" + isSuccess + "," + message);
                if (isSuccess) {
                    aliasCallback(SUCCESS);
                } else {
                    aliasCallback(ERROR);
                }



            }
        });
    }

    public void deleteAlias(String alias, String aliasType) {
        mPushAgent.deleteAlias(alias, aliasType, new UTrack.ICallBack() {
            @Override
            public void onMessage(boolean isSuccess, String s) {
                if (isSuccess) {
                    aliasCallback(SUCCESS);
                } else {
                    aliasCallback(ERROR);
                }
            }
        });
    }

    public void appInfo() {

    }
}
