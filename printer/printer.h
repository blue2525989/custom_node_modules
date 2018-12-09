#ifndef PRINTER_H
#define PRINTER_H

#include <node.h>
#include <node_object_wrap.h>
#include <iostream>

namespace print {
  // using object wrap allows us to create an object to send back to js
  class Printer : public node::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit Printer();
    ~Printer();

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Info(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Debug(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Error(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void GetLogLevel(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;
    v8::Local<v8::String> logLevel_;
  };

}

#endif
