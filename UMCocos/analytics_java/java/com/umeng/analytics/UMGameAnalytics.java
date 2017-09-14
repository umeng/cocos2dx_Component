package com.umeng.analytics;

/**
 * Created by zhz on 2017/9/13.
 */
import java.util.Map;
import android.content.Context;
import android.util.Log;

import com.umeng.analytics.MobclickAgent;
import com.umeng.analytics.game.UMGameAgent;
import com.umeng.commonsdk.UMConfigure;
import com.umeng.analytics.MobclickAgent.EScenarioType;

public class UMGameAnalytics {
    private static String wrapperType = "Cocos2d-x";
    private static String wrapperVersion = "4.7.1";

    private static Context mCtx = null;

    public static void init(Context context){
        if(context == null){
            Log.e("umcocos2dx","context is null");
            return;
        }
        mCtx = context.getApplicationContext();
        MobclickAgent.setScenarioType(context,EScenarioType.E_UM_GAME);
    }

    public static void event(String event_id, String label){
        if(mCtx != null){
            if(label == null){
                MobclickAgent.onEvent(mCtx,event_id);
            }else{
                MobclickAgent.onEvent(mCtx,event_id,label);
            }
        }
    }

    public static void event(String event_id,Map<String, String> map){
        if(mCtx != null){
            MobclickAgent.onEvent(mCtx,event_id,map);
        }
    }

    public static void event(String event_id,Map<String, String> map,int value){
        if(mCtx != null){
            MobclickAgent.onEventValue(mCtx,event_id,map,value);
        }
    }
}
