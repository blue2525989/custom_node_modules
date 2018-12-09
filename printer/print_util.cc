#include "print_util.h"

namespace print {
    void PrinterUtil::Print(v8::Local<v8::Value> str) {
        v8::Local<v8::String> strConvert = str->ToString();
        const char* realStr = ToCString(strConvert);
        // std::string strConvert(realStr);
        printf("\n%s", realStr);
    }

    // this is used more for logging stuff out to see whats going on
    const char* PrinterUtil::ToCString(v8::Local<v8::String> str) {
        v8::String::Utf8Value value(str);
        return *value ? *value : "<string conversion failed>";
    }
}
