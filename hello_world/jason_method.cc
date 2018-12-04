// // hello.cc
// #include <node.h>
//
// namespace jason_method {
//
// using v8::FunctionCallbackInfo;
// using v8::Isolate;
// using v8::Local;
// using v8::Object;
// using v8::String;
// using v8::Value;
//
// void JasonMethod(const FunctionCallbackInfo<Value>& args) {
//     Isolate* isolate = args.GetIsolate();
//     args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Jason is a brillant developer!"));
// }
//
// void init(Local<Object>& exports) {
//   NODE_SET_METHOD(exports, "jason", JasonMethod);
// }
//
// NODE_MODULE(addon, init)
//
// }
