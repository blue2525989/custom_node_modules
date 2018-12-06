#include <nan.h>


using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
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

void ForEach(const Nan::FunctionCallbackInfo<v8::Value>& info) {

    Isolate* isolate = info.GetIsolate();
    if (info.Length() < 2)
    {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments.")
        ));
        return;
    }
    // check argument types
    if (!info[0]->IsArray() || !info[1]->IsFunction())
    {
        isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong type of arguments")
        ));
        return;
    }

    // get the call back function
    Local<Function> cb = Local<Function>::Cast(info[1]);
    const unsigned argc = 1;

    // iterate through array and call callBackFunction on each element
    Local<Array> array = Local<Array>::Cast(info[0]);
    unsigned int arrayLength = array->Length();
    for (unsigned int i = 0; i < arrayLength; i++) {
        Local<Value> argv[argc] = {array->Get(i)};
        cb->Call(Null(isolate), argc, argv);
    }

}

// function that iterates over an array calling a function
void Map(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments.")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray() || !info[1]->IsFunction())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments")
      ));
      return;
  }

  Local<Function> cb = Local<Function>::Cast(info[1]);
  const unsigned argc = 1;

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  // vector<string> newArray;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> argv[argc] = {array->Get(i)};
      array->Get(i) = cb->Call(Null(isolate), argc, argv);
      // populate an array and return
      // Local<Value> element = array->Get(i);
      // Local<String> value = element->ToString();
      // const char* realValue = ToCString(argv[0]->ToString());
      // newArray.push_back(realValue);
  }

      // this returns stuff
    info.GetReturnValue().Set(array);
}

// function that iterates over an array calling a function
void FindFirst(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments.")
      ));
      return;
  }
  // check argument types
  //todo figure out how to check the comparator
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments")
      ));
      return;
  }

  Local<Value> compareValue = Local<Value>::Cast(info[1]);

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  Local<Value> realValue;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> arrayValue = array->Get(i);
      // todo figure out which one works catches it if any
      if (arrayValue->StrictEquals(compareValue))
      {
          info.GetReturnValue().Set(arrayValue);
          break;
      }
      else if (arrayValue == compareValue)
      {
          info.GetReturnValue().Set(arrayValue);
      }
  }
}

// void FindAll(const Nan::FunctionCallbackInfo<Value>& info) {
//   Isolate* isolate = info.GetIsolate();
//   // check argument length
//   if (info.Length() < 2)
//   {
//       isolate ->ThrowException(Exception::TypeError(
//         String::NewFromUtf8(isolate, "Wrong number of arguments.")
//       ));
//       return;
//   }
//   // check argument types
//   //todo figure out how to check the comparator
//   if (!info[0]->IsArray())
//   {
//       isolate->ThrowException(Exception::TypeError(
//         String::NewFromUtf8(isolate, "Wrong type of arguments")
//       ));
//       return;
//   }
//
//   Local<Value> compareValue = Local<Value>::Cast(info[1]);
//
//   Local<Array> array = Local<Array>::Cast(info[0]);
//   unsigned int arrayLength = array->Length();
//   Local<Value> realValue;
//   Local<Array> returnValues;
//   for (unsigned int i = 0; i < arrayLength; i++) {
//       Local<Value> arrayValue = array->Get(i);
//       // todo figure out which one works catches it if any
//       if (arrayValue->StrictEquals(compareValue))
//       {
//           // todo figure out how to put this element in return array, this compiles though :P
//           array->CloneElementAt(i);
//       }
//       else if (arrayValue == compareValue)
//       {
//           array->CloneElementAt(i);
//       }
//   }
//   info.GetReturnValue().Set(returnValues);
// }

// this is where we declare functions
void Init(Local<Object> exports) {
    exports->Set(Nan::New("forEach").ToLocalChecked(),
           Nan::New<FunctionTemplate>(ForEach)->GetFunction());

    exports->Set(Nan::New("map").ToLocalChecked(),
          Nan::New<FunctionTemplate>(Map)->GetFunction());

    exports->Set(Nan::New("findFirst").ToLocalChecked(),
          Nan::New<FunctionTemplate>(FindFirst)->GetFunction());


}

NODE_MODULE(array_util, Init)
