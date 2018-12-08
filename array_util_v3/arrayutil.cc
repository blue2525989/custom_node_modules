#include <nan.h>
#include "myobject.h"

void Arrays(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  info.GetReturnValue().Set(Arrays::NewInstance(info[0]));
}

void InitAll(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
  Nan::HandleScope scope;

  Arrays::Init();

  module->Set(Nan::New("exports").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(Arrays)->GetFunction());
}

NODE_MODULE(arrayutil, InitAll)
