package com.umeng.analytics;

/**
 * Created by zhz on 2017/9/13.
 */
import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.Iterator;
import java.util.ArrayList;
import android.content.Context;
import android.util.Log;

import com.umeng.analytics.game.UMGameAgent;
import com.umeng.commonsdk.UMConfigure;
import org.json.JSONException;
import org.json.JSONObject;

public class UMGameAnalytics {
    private static String wrapperType = "Cocos2d-x";
    private static String wrapperVersion = "6.0.0";

    private static Context mCtx = null;

    public static void init(Context context){
        if(context == null){
            Log.e("umcocos2dx","context is null");
            return;
        }
        mCtx = context.getApplicationContext();
        UMGameAgent.init(context);
    }

    public static void event(String event_id, String label){
        if(mCtx != null){
            if(label == null){
                UMGameAgent.onEvent(mCtx,event_id);
            }else{
                UMGameAgent.onEvent(mCtx,event_id,label);
            }
        }
    }

    public static void event(String event_id,Map<String, String> map){
        if(mCtx != null){
            UMGameAgent.onEvent(mCtx,event_id,map);
        }
    }

    public static void event(String event_id,Map<String, String> map,int value){
        if(mCtx != null){
            UMGameAgent.onEventValue(mCtx,event_id,map,value);
        }
    }
    public static void registerSuperProperty(Map<String, String> map){
        Iterator entries = map.entrySet().iterator();
        JSONObject json = new JSONObject();
        while (entries.hasNext()) {
            Map.Entry entry = (Map.Entry) entries.next();
            String key = (String)entry.getKey();
            String value = (String)entry.getValue();
            try {
                json.put(key,value);
            }catch (JSONException e){

            }
            //MobclickAgent.registerPreProperties(mCtx,key,(Object)value);
        }
        UMGameAgent.registerPreProperties(mCtx,json);
    }
    public static void unregisterSuperProperty(String propertyName){
        UMGameAgent.unregisterPreProperty(mCtx, propertyName);
    }
    public static String getSuperProperties(){
        return UMGameAgent.getPreProperties(mCtx).toString();
    }

    public static void clearSuperProperties(){
        UMGameAgent.clearPreProperties(mCtx);
    }

    public static void setFirstLaunchEvent(String[] events){
        List list = new ArrayList();
        for(int i=0;i<events.length;i++){
            list.add(events[i]);
        }
        UMGameAgent.setFirstLaunchEvent(mCtx, list);
    }
}
