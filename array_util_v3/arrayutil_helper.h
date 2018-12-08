#ifndef ARRAYUTIL_SLAVE_H
#define ARRAYUTIL_SLAVE_H

#include <nan.h>

class Arrays : public Nan::ObjectWrap {
 public:
  static void Init();
  static v8::Local<v8::Object> NewInstance(v8::Local<v8::Value> arg);

 private:
  Arrays();
  ~Arrays();

  // init objects
  static Nan::Persistent<v8::Function> constructor;
  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  // custom functions
  static void ForEach(const Nan::FunctionCallbackInfo<v8::Value>& info);
  v8::Local<v8::Array> array_;
};

#endif
