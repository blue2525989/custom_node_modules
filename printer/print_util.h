#ifndef PRINTER_UTIL_H
#define PRINTER_UTIL_H
#include <node.h>

namespace print {
    class PrinterUtil {
      public:
        static void Print(v8::Local<v8::Value> str);
        static const char* ToCString(v8::Local<v8::String> str);
    };
}

#endif
