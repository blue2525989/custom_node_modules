#include <nan.h>
#include "arrayutil_helper.h"

using namespace v8;

Arrays::Arrays() {};
Arrays::~Arrays() {};

Nan::Persistent<v8::Function> Arrays::constructor;

void Arrays::Init() {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("Arrays").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(Nan::New("forEach").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(ForEach));

  constructor.Reset(tpl->GetFunction());
}

void Arrays::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Arrays* obj = new Arrays();
  obj->array_ = Local<Array>::Cast(info[0]);
  obj->Wrap(info.This());

  info.GetReturnValue().Set(info.This());
}


v8::Local<v8::Object> Arrays::NewInstance(v8::Local<v8::Value> arg) {
  Nan::EscapableHandleScope scope;

  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { arg };
  v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
  v8::Local<v8::Object> instance = cons->NewInstance(argc, argv);

  return scope.Escape(instance);
}

void Arrays::ForEach(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  Arrays* obj = ObjectWrap::Unwrap<Arrays>(info.This());
  // printf("%s", obj);

  // Isolate* isolate = info.GetIsolate();
  //
  // if (!info[0]->IsFunction())
  // {
  //     isolate->ThrowException(Exception::TypeError(
  //       String::NewFromUtf8(isolate, "Wrong type of argument, arg[0] must be a function.")
  //     ));
  //     return;
  // }
  // get array
  v8::Local<v8::Array> array = obj->array_;
  unsigned int arrayLength = array->Length();

  // // get the call back function
  // Handle<Function> cb = Handle<Function>::Cast(info[0]);
  // Nan::Callback *cbp = new Nan::Callback(cb);
  // const unsigned argc = 1;
  //
  // unsigned int i = 0;
  // Local<Value> argv[argc] = {array->Get(i)};
  // Handle<Value> cb_result = cb->Call(Nan::GetCurrentContext()->Global(), argc, argv);//Nan::GetCurrentContext()->Global()
  // if (!cb_result->IsNull() || !cb_result->IsUndefined())
  // {
  //     array->Set(i, argv[0]);
  // }
  // else
  // {
  //     array->Set(i, cb_result);
  // }

  // // iterate through array and call callBackFunction on each element
  // for (unsigned int i = 0; i < arrayLength; i++) {
  //     Local<Value> argv[argc] = {array->Get(i)};
  //     Handle<Value> cb_result = cb->Call(Null(isolate), argc, argv);//Nan::GetCurrentContext()->Global()
  //     if (!cb_result->IsNull() || !cb_result->IsUndefined())
  //     {
  //         array->Set(i, argv[0]);
  //     }
  //     else
  //     {
  //         array->Set(i, cb_result);
  //     }
  // }

  // set internal array back
  // obj->array_ = array;
  // info.GetReturnValue().Set(obj->array_);
}
