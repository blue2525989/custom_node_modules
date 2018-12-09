#ifndef PRINTER_UTIL_H
#define PRINTER_UTIL_H
#include <node.h>

namespace print {
    class PrinterUtil {
      public:
        static void Print(const v8::FunctionCallbackInfo<v8::Value>& args, v8::Local<v8::Value> str);
        static const char* ToCString(v8::Local<v8::String> str);

    private:
        static void LogObjectHandler(const v8::FunctionCallbackInfo<v8::Value>& args, v8::Local<v8::Value> str);
    };
}

#endif
