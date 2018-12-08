
var Arrays = require('bindings')('arrayutil');

function forEach() {
  var testArray1 = [];
  var testArray2 = [];

  for (var i = 0; i < 5000; i++) {
    testArray1.push("bob");
  }
  console.log("hello");
  console.log("hello", Arrays);
  var array = Arrays(testArray1);
  array.forEach(function ()  { console.log("element") });
  console.log("goodbye");
}

// var obj = Arrays(10);
// console.log( obj.plusOne() ); // 11
// console.log( obj.plusOne() ); // 12
// console.log( obj.plusOne() ); // 13
//
// var obj2 = Arrays(20);
// console.log( obj2.plusOne() ); // 21
// console.log( obj2.plusOne() ); // 22
// console.log( obj2.plusOne() ); // 23
forEach();
