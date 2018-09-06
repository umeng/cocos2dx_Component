#!/bin/bash
myPath="UMCocos"
pro_name="Cocos2dx_Cpp"
version="5.0.0"
platform="cocos2dxcpp"
sharename="share_${platform}_$version.zip"
pushname="push_${platform}_$version.zip"
analyticsname="analytics_${platform}_$version.zip"
commonname="common_${platform}_$version.zip" 


sharedic=${pro_name}"/share/share_${platform}_$version/"
pushdic=${pro_name}"/push/push_${platform}_$version/"
analyticsdic=${pro_name}"/analytics/analytics_${platform}_$version/"
commonndic=${pro_name}"/common/common_${platform}_$version/" 


common_android=${commonndic}"common_java/java/com/umeng/common"
common_ios=${commonndic}"common_cc/"
analytics_android=${analyticsdic}"analytics_java/java/com/umeng/analytics"
analytics_ios=${analyticsdic}"analytics_cc/"
push_android=${pushdic}"push_java/java/com/umeng/push"
push_android_lib=${pushdic}"push_java/"
push_ios=${pushdic}"push_cc/"
share_android=${sharedic}"share_java/java/com/umeng/share"
share_ios=${sharedic}"share_cc/"

rm -r ${pro_name}
rm -r ${pro_name}.zip


if [ ! -d "$pro_name" ]; then
	
 mkdir "$pro_name"

fi 
if [ ! -d "$common_android" ]; then
	
 mkdir -p "$common_android"
fi 
if [ ! -d "$common_ios" ]; then
	
 mkdir -p "$common_ios"
fi 
if [ ! -d "$analytics_android" ]; then
	
 mkdir -p "$analytics_android"
fi 
if [ ! -d "$analytics_ios" ]; then
	
 mkdir -p "$analytics_ios"
fi 
if [ ! -d "$push_android" ]; then
	
 mkdir -p "$push_android"
fi 
if [ ! -d "$push_ios" ]; then
	
 mkdir -p "$push_ios"
fi 
if [ ! -d "$share_android" ]; then
	
 mkdir -p "$share_android"
fi 
if [ ! -d "$share_ios" ]; then
	
 mkdir -p "$share_ios"
fi 

## android common
cp ./proj.android-studio/app/src/com/umeng/common/*.java "$common_android"
## android 统计
cp ./proj.android-studio/app/src/com/umeng/analytics/*.java "$analytics_android"
## android 推送
cp ./proj.android-studio/app/src/com/umeng/push/*.java "$push_android"
cp -r ./proj.android-studio/push "$push_android_lib"
## android 分享
cp ./proj.android-studio/app/src/com/umeng/social/*.java "$share_android"

## ios common
cp ./Classes/Common/*.h "$common_ios"
cp ./Classes/Common/*.mm "$common_ios"
cp ./Classes/Common/*.cpp "$common_ios"
## ios 统计
cp ./Classes/analytics/MobClickCpp.* "$analytics_ios"
cp ./Classes/analytics/DplusMobClickCpp.* "$analytics_ios"
## ios 推送
cp ./Classes/push/CCUMPushSDK.* "$push_ios"

## ios 分享
cp ./Classes/share/CCUMSocialSDK.* "$share_ios"


cd ${pro_name}
cd share
# zip -r -m $sharename . -i "/share_${platform}_$version/*"
cd ../../
cd ${pro_name}
cd push
# zip -r -m $pushname  . -i "/push_${platform}_$version/*"
cd ../../
cd ${pro_name}
cd analytics
# zip -r -m $analyticsname  . -i "/analytics_${platform}_$version/*"
cd ../../
cd ${pro_name}
cd common
# zip -r -m $commonname . -i  "/common_${platform}_$version/*"
cd ../../
zip -r -m ${pro_name}".zip" . -i "/${pro_name}/*"

#########################版本号修改##################################
# share修改
value=`cat alljson/UM_share.json | awk -F '"' '/platform_version/{print$4}'`
echo $value
sed -i '' "s/$value/$version/g" alljson/UM_share.json
# push修改
value=`cat alljson/UM_push.json | awk -F '"' '/platform_version/{print$4}'`
echo $value
sed -i '' "s/$value/$version/g" alljson/UM_push.json
# common
value=`cat alljson/UM_common.json | awk -F '"' '/platform_version/{print$4}'`
echo $value
sed -i '' "s/$value/$version/g" alljson/UM_common.json
# analytics
value=`cat alljson/UM_analytics.json | awk -F '"' '/platform_version/{print$4}'`
echo $value
sed -i '' "s/$value/$version/g" alljson/UM_analytics.json
#########################版本号修改##################################
./addlog.py