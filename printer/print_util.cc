#include "print_util.h"

namespace print {
    void PrinterUtil::Print(const v8::FunctionCallbackInfo<v8::Value>& args, v8::Local<v8::Value> str) {
        if (str->IsObject()) {
            // todo force to better object logging
            LogObjectHandler(args, str);
        } else {
            v8::Local<v8::String> strConvert = str->ToString();
            const char* realStr = ToCString(strConvert);
            // std::string strConvert(realStr);
            printf("%s\n", realStr);
        }
    }

    // this is used more for logging stuff out to see whats going on
    const char* PrinterUtil::ToCString(v8::Local<v8::String> str) {
        v8::String::Utf8Value value(str);
        return *value ? *value : "<string conversion failed>";
    }

    void PrinterUtil::LogObjectHandler(const v8::FunctionCallbackInfo<v8::Value>& args, v8::Local<v8::Value> str) {
        v8::Isolate* isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::Object> obj = str->ToObject(context).ToLocalChecked();
        v8::Local<v8::Array> props = obj->GetOwnPropertyNames(context).ToLocalChecked();

      for(int i = 0, l = props->Length(); i < l; i++) {
        v8::Local<v8::Value> localKey = props->Get(i);
        v8::Local<v8::Value> localVal = obj->Get(context, localKey).ToLocalChecked();
        const char* key = ToCString(localKey->ToString());
        const char* val = ToCString(localVal->ToString());
        printf("%s : ", key);
        printf("%s\n", val);
      }
    }
}
