#include <nan.h>

using v8::FunctionTemplate;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Exception;
using v8::Persistent;
using v8::Context;
using v8::Handle;
using v8::Boolean;

// convert v8 string to cpp string
// this is used more for logging stuff out to see whats going on
const char* ToCString(Local<String> str) {
    String::Utf8Value value(str);
    return *value ? *value : "<string conversion failed>";
}

// for each - added
void ForEach(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    Isolate* isolate = info.GetIsolate();

    // check arguments length
    if (info.Length() < 2)
    {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=function.")
        ));
        return;
    }
    // check argument[0] types
    if (!info[0]->IsArray())
    {
        isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong type of argument, arg[0] must be array.")
        ));
        return;
    }
    // check argument[1] types
    if (!info[1]->IsFunction())
    {
        isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong type of argument, arg[1] must be a function.")
        ));
        return;
    }

    // get the call back function
    Handle<Function> cb = Handle<Function>::Cast(info[1]);
    Nan::Callback *cbp = new Nan::Callback(cb);
    // init stuff for cb
    const unsigned argc = 1;

    // iterate through array and call callBackFunction on each element
    Local<Array> array = Local<Array>::Cast(info[0]);
    unsigned int arrayLength = array->Length();
    for (unsigned int i = 0; i < arrayLength; i++) {
        Local<Value> argv[argc] = {array->Get(i)};
        Handle<Value> cb_result = cbp->Call(Nan::GetCurrentContext()->Global(), argc, argv);
        if (!cb_result->IsNull() || !cb_result->IsUndefined())
        {
            array->Set(i, argv[0]);
        }
        else
        {
            array->Set(i, cb_result);
        }
    }
}

// function that iterates over an array calling a function
void Map(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();

  // check arguments length
  if (info.Length() < 2)
  {
    isolate ->ThrowException(Exception::TypeError(
      String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=function.")
      ));
      return;
  }
  // check argument[0] types
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of argument, arg[0] must be array.")
      ));
      return;
  }
  // check argument[1] types
  if (!info[1]->IsFunction())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of argument, arg[1] must be a function.")
      ));
      return;
  }

  // grab function
  Local<Function> cb = Local<Function>::Cast(info[1]);
  Nan::Callback *cbp = new Nan::Callback(cb);
  // init stuff for cb
  const unsigned argc = 1;

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  // iterate and perform cb on each element
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> argv[argc] = {array->Get(i)};
      Handle<Value> cb_result = cbp->Call(Nan::GetCurrentContext()->Global(), argc, argv);
      if (!cb_result->IsNull() || !cb_result->IsUndefined())
      {
          array->Set(i, argv[0]);
      }
      else
      {
          array->Set(i, cb_result);
      }
  }
      // this returns stuff
    info.GetReturnValue().Set(array);
}

// find first - added
void FindFirst(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=compareValue.")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of argument, arg[0] must be array.")
      ));
      return;
  }

  Local<Value> compareValue = Local<Value>::Cast(info[1]);

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  Local<Value> realValue;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> arrayValue = array->Get(i);
      if (arrayValue->StrictEquals(compareValue))
      {
          info.GetReturnValue().Set(arrayValue);
          break;
      }
  }
}

// find all - added
void FindAll(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();

  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=compareValue.")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array")
      ));
      return;
  }
  if (info[1]->IsFunction())
  {

      std::string str("did it work");
      printf("%s\n", str.c_str());

      // std::string strFunc(strFuncInfo);
      // printf("%s\n", info[1]->ToString());
      //todo if it is a function and results in true we collect it
  }

  Local<Value> compareValue = Local<Value>::Cast(info[1]);

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  unsigned int counter = 0;
  unsigned int argc = 1;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> arrayValue = array->Get(i);
      if (info[1]->IsFunction())
      {
          // std::string str("did it work");
          // printf("%s\n", str.c_str());
          //
          // // std::string strFunc(strFuncInfo);
          // printf("%s\n", info[1]->ToString());
          //todo if it is a function and results in true we collect it

        // grab function
        // Local<Value> argv[] = {arrayValue};
        Local<Function> cbp = Local<Function>::Cast(info[1]);
        Handle<Value> cb_result = cbp->Call(Null(isolate), arrayValue, argc);
        // if (!cb_result->IsUndefined())
        // {
        //     if (cb_result->IsBoolean() || cb_result->IsBooleanObject())
        //     {
        //         std::string wow("wow made it");
        //         printf("%s\n", wow.c_str());
        //     }
        // }
      }
      if (arrayValue->StrictEquals(compareValue))
      {
          counter++;
      }
  }
  // double process, look for ways to get size of matches and init array with that, or trim array
  Handle<Array> returnValues = Array::New(isolate, counter);
  counter = 0;
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> arrayValue = array->Get(i);
      if (arrayValue->StrictEquals(compareValue))
      {
          returnValues->Set(counter++, arrayValue);
      }
  }

  info.GetReturnValue().Set(returnValues);
}

// copy array - added
void Copy(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 1)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array")
      ));
      return;
  }

  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  Handle<Array> returnValues = Array::New(isolate, arrayLength);
  for (unsigned int i = 0; i < arrayLength; i++) {
      Local<Value> arrayValue = array->Get(i);
      returnValues->Set(i, arrayValue);
  }

  info.GetReturnValue().Set(returnValues);
}

// count - added
void Count(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() > 1)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array optional:1=comparator")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array")
      ));
      return;
  }


  unsigned int counter = 0;
  Local<Array> array = Local<Array>::Cast(info[0]);
  unsigned int arrayLength = array->Length();
  for (unsigned int i = 0; i < arrayLength; i++) {
      counter++;
  }
  info.GetReturnValue().Set(counter);
  return;
}

// strict equals - added
void StrictEquals(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=compareValue.")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray() || !info[1]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array arg[1] must be array")
      ));
      return;
  }

  Local<Boolean> falseBool = Boolean::New(isolate, false);

  Local<Array> array = Local<Array>::Cast(info[0]);
  Local<Array> arrayCompare = Local<Array>::Cast(info[1]);
  unsigned int arrayLength = array->Length();
  unsigned int arrayCompareLength = arrayCompare->Length();
  unsigned int counter = 0;
  // if (arrayLength != arrayCompareLength)
  // {
  //     info.GetReturnValue().Set(falseBool);
  //     return;
  // }
  // for (unsigned int i = 0; i < arrayLength; i++) {
  //     for (unsigned int x = 0; x < arrayCompareLength; x++) {
  //         // use a counter to increament to step piece by piece
  //         Local<Value> arrayValue = array->Get(counter++);
  //         Local<Value> arrayCompareValue = array->Get(x);
  //         if (!arrayValue->StrictEquals(arrayCompareValue))
  //         {
  //             info.GetReturnValue().Set(falseBool);
  //             return;
  //         }
  //
  //     }
  //     break;
  // }
  Local<Boolean> trueBool = Boolean::New(isolate, true);

  if (array->StrictEquals(arrayCompare))
  {
      info.GetReturnValue().Set(trueBool);
      return;
  }
  else
  {
      info.GetReturnValue().Set(falseBool);
      return;
  }
  // info.GetReturnValue().Set(trueBool);
  // return;
}


// todo fix these
// equals - added
void Equals(const Nan::FunctionCallbackInfo<Value>& info) {
  Isolate* isolate = info.GetIsolate();
  // check argument length
  if (info.Length() < 2)
  {
      isolate ->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array 1=compareValue.")
      ));
      return;
  }
  // check argument types
  if (!info[0]->IsArray() || !info[1]->IsArray())
  {
      isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array arg[1] must be array")
      ));
      return;
  }

  Local<Array> array = Local<Array>::Cast(info[0]);
  Local<Array> arrayCompare = Local<Array>::Cast(info[1]);
  unsigned int arrayLength = array->Length();
  unsigned int arrayCompareLength = arrayCompare->Length();
  unsigned int counter = 0;

  Local<Boolean> falseBool = Boolean::New(isolate, false);

  Local<Boolean> trueBool = Boolean::New(isolate, true);

  if (arrayLength != arrayCompareLength)
  {
      info.GetReturnValue().Set(falseBool);
      return;
  }

  if (array == arrayCompare)
  {
      info.GetReturnValue().Set(trueBool);
      return;
  }
  else
  {
      info.GetReturnValue().Set(falseBool);
      return;
  }
  // for (unsigned int i = 0; i < arrayLength; i++) {
  //     for (unsigned int x = 0; x < arrayCompareLength; x++) {
  //         // use a counter to increament to step piece by piece
  //         Local<Value> arrayValue = array->Get(counter++);
  //         Local<Value> arrayCompareValue = array->Get(x);
  //         if (arrayValue != arrayCompareValue)
  //         {
  //             info.GetReturnValue().Set(falseBool);
  //             return;
  //         }
  //
  //     }
  //     break;
  // }
  // info.GetReturnValue().Set(trueBool);
  // return;
}

/* boolean functions **/

// checks if empty - added
void IsEmpty(const Nan::FunctionCallbackInfo<Value>& info) {
    Isolate* isolate = info.GetIsolate();

    if (info.Length() < 1)
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array")
        ));
        return;
    }
    if (!info[0]->IsArray())
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong type of arguments, arg[0] must be array")
        ));
        return;
    }

    Local<Boolean> falseBool = Boolean::New(isolate, false);

    Local<Boolean> trueBool = Boolean::New(isolate, true);

    Local<Array> array = Local<Array>::Cast(info[0]);
    if (array->Length() > 0)
    {
        info.GetReturnValue().Set(falseBool);
    }
    else
    {
        info.GetReturnValue().Set(trueBool);
    }
}

// checks if array - added
void IsArray(const Nan::FunctionCallbackInfo<Value>& info) {
    Isolate* isolate = info.GetIsolate();

    if (info.Length() < 1)
    {
        isolate->ThrowException(Exception::TypeError(
            String::NewFromUtf8(isolate, "Wrong number of arguments, required 0=array")
        ));
        return;
    }

    Local<Boolean> falseBool = Boolean::New(isolate, false);

    Local<Boolean> trueBool = Boolean::New(isolate, true);

    if (info[0]->IsArray())
    {
        info.GetReturnValue().Set(trueBool);
    }
    else
    {
        info.GetReturnValue().Set(falseBool);
    }
}

// this is where we declare functions
void Init(Local<Object> exports) {
    exports->Set(Nan::New("forEach").ToLocalChecked(),
           Nan::New<FunctionTemplate>(ForEach)->GetFunction());

    exports->Set(Nan::New("map").ToLocalChecked(),
          Nan::New<FunctionTemplate>(Map)->GetFunction());

    exports->Set(Nan::New("findFirst").ToLocalChecked(),
          Nan::New<FunctionTemplate>(FindFirst)->GetFunction());

    exports->Set(Nan::New("findAll").ToLocalChecked(),
            Nan::New<FunctionTemplate>(FindAll)->GetFunction());

    exports->Set(Nan::New("count").ToLocalChecked(),
            Nan::New<FunctionTemplate>(Count)->GetFunction());

    exports->Set(Nan::New("isEmpty").ToLocalChecked(),
            Nan::New<FunctionTemplate>(IsEmpty)->GetFunction());

    exports->Set(Nan::New("isArray").ToLocalChecked(),
            Nan::New<FunctionTemplate>(IsArray)->GetFunction());

    exports->Set(Nan::New("copy").ToLocalChecked(),
            Nan::New<FunctionTemplate>(Copy)->GetFunction());

    exports->Set(Nan::New("strictEquals").ToLocalChecked(),
            Nan::New<FunctionTemplate>(StrictEquals)->GetFunction());

    exports->Set(Nan::New("equals").ToLocalChecked(),
            Nan::New<FunctionTemplate>(Equals)->GetFunction());
}

NODE_MODULE(array_util, Init)
