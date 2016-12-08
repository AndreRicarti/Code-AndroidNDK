//Information Device in C++
//@author Son182
//@Date : 2016-12-08

#include <jni.h>
#include <string>

extern "C"
jstring
Java_com_example_aricarti_informationdevice_Imei_informationDevice(JNIEnv *env) {
    jclass build_class = env->FindClass("android/os/Build");
    jclass versionClass = env->FindClass("android/os/Build$VERSION");

    jfieldID model_product = env->GetStaticFieldID(build_class, "PRODUCT", "Ljava/lang/String;");
    jstring model_objProduct  = (jstring)env->GetStaticObjectField(build_class, model_product);

    jfieldID model_release = env->GetStaticFieldID(versionClass, "RELEASE", "Ljava/lang/String;");
    jstring model_objRelease  = (jstring)env->GetStaticObjectField(versionClass, model_release);

    jfieldID model_display = env->GetStaticFieldID(build_class, "MANUFACTURER", "Ljava/lang/String;");
    jstring model_objDisplay  = (jstring)env->GetStaticObjectField(build_class, model_display);

    const char *deviceProduct = env->GetStringUTFChars(model_objProduct, 0);
    const char *deviceRelease = env->GetStringUTFChars(model_objRelease, 0);
    const char *deviceDisplay = env->GetStringUTFChars(model_objDisplay, 0);

    char message[1000];
    strcpy(message, "Nome = ");
    strcat(message, deviceProduct);
    strcat(message, "\n");

    strcat(message, "Versão Android = ");
    strcat(message, deviceRelease);
    strcat(message, "\n");

    strcat(message, "Fabricante = ");
    strcat(message, deviceDisplay);

    return env->NewStringUTF(message);
}

