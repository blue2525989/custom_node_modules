#include <node.h>
#include <string>

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Exception;
using std::vector;
using std::vector;
using std::string;



const char* ToCString(Local<String> str) {
    String::Utf8Value value(str);
    return *value ? *value : "<string conversion failed>";
}

// function that
void ForEachVoid(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments.")
      ));
      return;
  }

  if (!args[0]->IsArray() || !args[1]->IsFunction())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments")
      ));
      return;
  }


  Local<Array> array = Local<Array>::Cast(args[0]);
  unsigned int arrayLength = array->Length();
  vector<string> newArray;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> element = array->Get(i);
      Local<String> value = element->ToString();
      const char* realValue = ToCString(value);
      newArray.push_back(realValue);
  }

  // Local<Array> returnArray = Array::New(newArray);
  args.GetReturnValue().Set(array);

  // Local<Function> callBack = Local<Function>Cast(args[1]);
  // CallBack cb(callBack);
}

void init(Local<Object>& exports) {
  NODE_SET_METHOD(exports, "forEachVoid", ForEachVoid);
}

NODE_MODULE(addon, init)

}
