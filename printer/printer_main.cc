#include <node.h>
#include "printer.h"

namespace print {

    using v8::Local;
    using v8::Object;

    void InitAll(Local<Object> exports) {
        Printer::Init(exports);
    }

    NODE_MODULE(printer_master, InitAll)
}
