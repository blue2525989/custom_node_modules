#include <node.h>
#include <string>

namespace array_util {

using v8::FunctionCallbackInfo;
using v8::Function;
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


// convert v8 string to cpp string
const char* ToCString(Local<String> str) {
    String::Utf8Value value(str);
    return *value ? *value : "<string conversion failed>";
}

// function that iterates over an array calling a function
void ForEachVoid(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  // check argument length
  if (args.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments.")
      ));
      return;
  }
  // check argument types
  if (!args[0]->IsArray() || !args[1]->IsFunction())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments")
      ));
      return;
  }

  Local<Function> cb = Local<Function>::Cast(args[1]);
  const unsigned argc = 1;

  Local<Array> array = Local<Array>::Cast(args[0]);
  unsigned int arrayLength = array->Length();
  vector<string> newArray;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> argv[argc] = {array->Get(i)};
      cb->Call(Null(isolate), argc, argv);
      /* populate an array and return
      Local<Value> element = array->Get(i);
      Local<String> value = element->ToString();
      const char* realValue = ToCString(value);
      newArray.push_back(realValue);
      */
  }
  // if wanting to return populated array
  // args.GetReturnValue().Set(array);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "forEachVoid", ForEachVoid);
}

NODE_MODULE(array_util, init)

}
