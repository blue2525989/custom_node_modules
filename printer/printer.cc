#include "printer.h"
#include "print_util.h"
#include <iostream>

namespace print {
    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::Persistent;
    using v8::String;
    using v8::Value;

    using v8::ReturnValue;

    Persistent<Function> Printer::constructor;

    Printer::Printer() {
    }

    Printer::~Printer() {
    }

    void Printer::Init(Local<Object> exports) {
        Isolate* isolate = exports->GetIsolate();

        // Prepare constructor template
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
        tpl->SetClassName(String::NewFromUtf8(isolate, "Log"));
        tpl->InstanceTemplate()->SetInternalFieldCount(4);

        // Prototypev
        NODE_SET_PROTOTYPE_METHOD(tpl, "info", Info);
        NODE_SET_PROTOTYPE_METHOD(tpl, "debug", Debug);
        NODE_SET_PROTOTYPE_METHOD(tpl, "error", Error);
        NODE_SET_PROTOTYPE_METHOD(tpl, "getLogLevel", GetLogLevel);

        constructor.Reset(isolate, tpl->GetFunction());
        exports->Set(String::NewFromUtf8(isolate, "Log"),
                    tpl->GetFunction());
    }

    void Printer::New(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        if (args.IsConstructCall()) {
            // Invoked as constructor
            Printer* printer = new Printer();
            printer->Wrap(args.This());
            args.GetReturnValue().Set(args.This());
        } else {
            // Invoked as plain function `Printer(...)`, turn into construct call.
            Local<Context> context = isolate->GetCurrentContext();
            Local<Function> cons = Local<Function>::New(isolate, constructor);
            Local<Object> result =
                cons->NewInstance(context, 0, 0).ToLocalChecked();
        args.GetReturnValue().Set(result);
      }
    }

    void Printer::Info(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Printer* obj = ObjectWrap::Unwrap<Printer>(args.Holder());
        obj->logLevel_ = "info";
        // Local<Value> val = Local<Value>::Cast(args[0]);
        PrinterUtil* printUtil = new PrinterUtil;
        printUtil->Print(args, args[0]);
        // obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }

    void Printer::Debug(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Printer* obj = ObjectWrap::Unwrap<Printer>(args.Holder());
        obj->logLevel_ = "debug";
        // Local<Value> val = Local<Value>::Cast(args[0]);
        PrinterUtil* printUtil = new PrinterUtil;
        printUtil->Print(args, args[0]);
        args.GetReturnValue().Set(args.This());
    }

    void Printer::Error(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Printer* obj = ObjectWrap::Unwrap<Printer>(args.Holder());
        obj->logLevel_ = "error";
        // Local<Value> val = Local<Value>::Cast(args[0]);
        PrinterUtil* printUtil = new PrinterUtil;
        printUtil->Print(args, args[0]);
        printf("\n\n ->>%s \n\n", obj->logLevel_.c_str());
        args.GetReturnValue().Set(args.This());
    }

    //todo this is not returning the value, possibly not being set
    // this function will be used when setting levels for logging out
    // will need to dive in and see if I can get main process arguments to determine
    void Printer::GetLogLevel(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Printer* obj = ObjectWrap::Unwrap<Printer>(args.Holder());
        PrinterUtil* printerUtil = new PrinterUtil;
        // const char* logLevel = printerUtil->ToCString(obj->logLevel_);
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, obj->logLevel_.c_str()));
    }
}
