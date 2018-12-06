#include <node.h>
#include <string>

namespace array_iterate_generator {

using v8::FunctionCallbackInfo;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Exception;
using v8::Promise;
using v8::Persistent;
using v8::CopyablePersistentTraits;
using std::string;

// Persistent<Promise::Resolver, CopyablePersistentTraits<Promise::Resolver>> PersistentResolver;
// unordered_map<long long, PersistentResolver> resolvers;
// long long resolverID = 0;


// function that iterates over an array calling a function
void ForEachPromise(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // get the call back function
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;

  Local<Promise::Resolver> resolver = v8::Promise::Resolver::New(isolate);
  resolver->Resolve(cb->Call(Null(isolate), 0, 0));
  args.GetReturnValue().Set(resolver->GetPromise());

  // store resolver in a map, to find it later when it's ready to resolve
  // long long currentID = resolverID++;
  // resolvers[currentID] = PersistentResolver(isolate, resolver);
  //
  // thread t([file, isolate, currentID](){
  //
  //     schedule([currentID, isolate, buffer]() {
  //
  //         auto persistantResolver = resolvers[currentID];
  //         Local<Promise::Resolver> resolver = Local<Promise::Resolver>::New(isolate, persistantResolver);
  //         resolver->Resolve();
  //
  //         resolvers.erase(currentID);
  //     });
  //
  // });
  // t.detach();

  // check argument length
  // if (args.Length() < 2)
  // {
  //     isolate ->ThrowException(Exception::TypeError(
  //       String::NewFromUtf8(isolate, "Wrong number of arguments.")
  //     ));
  //     return;
  // }
  // // check argument types
  // if (!args[0]->IsArray() || !args[1]->IsFunction())
  // {
  //     isolate->ThrowException(Exception::TypeError(
  //       String::NewFromUtf8(isolate, "Wrong type of arguments")
  //     ));
  //     return;
  // }

  // get the call back function
  // Local<Function> cb = Local<Function>::Cast(args[1]);
  // const unsigned argc = 1;

  // iterate through array and call callBackFunction on each element
  // Local<Array> array = Local<Array>::Cast(args[0]);
  // unsigned int arrayLength = array->Length();
  // for (unsigned int i = 0; i < arrayLength; i++) {
  //     Local<Value> argv[argc] = {array->Get(i)};
  //     cb->Call(Null(isolate), argc, argv);
  // }
}

// set init object for class
void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "forEachPromise", ForEachPromise);
}

// set node_module
NODE_MODULE(array_iterate_generator, init)

}
