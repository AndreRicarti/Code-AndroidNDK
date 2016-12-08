/*
# Imei of Device in C
    # @author Son182
    # @Date : 2016-12-08
*/

#include <jni.h>
#include <malloc.h>

JNIEXPORT jstring JNICALL Java_com_example_aricarti_informationdevice_Imei_imei(JNIEnv *env, jobject context){

    jclass cls = (*env)->FindClass(env, "android/content/Context");
    jmethodID mid = (*env)->GetMethodID(env, cls, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");
    jfieldID fid = (*env)->GetStaticFieldID(env, cls, "TELEPHONY_SERVICE", "Ljava/lang/String;");
    jstring str = (*env)->GetStaticObjectField(env, cls, fid);
    jobject telephony = (*env)->CallObjectMethod(env, context, mid, str);
    cls = (*env)->FindClass(env, "android/telephony/TelephonyManager");
    mid =(*env)->GetMethodID(env, cls, "getDeviceId", "()Ljava/lang/String;");
    str = (*env)->CallObjectMethod(env, telephony, mid);
    jsize len = (*env)->GetStringUTFLength(env, str);
    char* deviceId = calloc(len + 1, 1);
    (*env)->GetStringUTFRegion(env, str, 0, len, deviceId);
    (*env)->DeleteLocalRef(env, str);
    /* to get a string in deviceId */

    return (*env)->NewStringUTF(env, deviceId);
}