var Arrays = require('bindings')('array_util');

function count() {
  var testArr1 = []
  for (var i = 0; i < 50000; i++) {
    testArr1.push("array_util");
  }

  console.log("\n");
  var startTime = new Date();
  var result = Arrays.count(testArr1);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("count result", result);
  console.log("\n");
}

function isArray() {
  var testArr1 = []
  for (var i = 0; i < 50000; i++) {
    testArr1.push("array_util");
  }

  console.log("\n");
  var startTime = new Date();
  var result = Arrays.isArray(testArr1);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("isArray result", result);


  var testObj = {val1: "some val1", val2: "some val2"};
  var startTime2 = new Date();
  var result2 = Arrays.isArray(testObj);
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("isArray result 2", result2);
  console.log("\n");
}

function isEmpty() {
  var testArr1 = []
  for (var i = 0; i < 50000; i++) {
    testArr1.push("array_util");
  }

  console.log("\n");
  var startTime = new Date();
  var result = Arrays.isEmpty(testArr1);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("isEmpty result", result);


  var testArr2 = [];
  var startTime2 = new Date();
  var result2 = Arrays.isEmpty(testArr2);
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("isEmpty result 2", result2);
  console.log("\n");
}
//
// function equal() {
//   var testArr1 = []
//   var testArr2 = [];
//   for (var i = 0; i < 50000; i++) {
//     testArr1.push(true);
//   }
//
//   console.log("\n");
//   var startTime = new Date();
//   var result = Arrays.equals(testArr1, testArr2);
//   var endTime = new Date();
//   console.log("function execution time", endTime - startTime);
//   console.log("equal result", result);
//
//   // for (var i = 0; i < 50000; i++) {
//   // }
//
//   var startTime2 = new Date();
//   var result2 = Arrays.equals(testArr1, testArr2);
//   var endTime2 = new Date();
//   console.log("function execution time 2", endTime2 - startTime2);
//   console.log("equal result 2", result2);
//   console.log("\n");
// }
//
// function strictEquals() {
//   var testArr1 = [];
//   var testArr2 = [];
//   var same = "same";
//   for (var i = 0; i < 50000; i++) {
//     testArr1.push(same);
//   }
//
//   console.log("\n");
//   var startTime = new Date();
//   var result = Arrays.strictEquals(testArr1, testArr2);
//   var endTime = new Date();
//   console.log("function execution time", endTime - startTime);
//   console.log("strictEquals result", result);
//
//   for (var i = 0; i < 50000; i++) {
//     testArr2.push(same);
//   }
//
//   var startTime2 = new Date();
//   var result2 = Arrays.strictEquals(testArr1, testArr2);
//   var endTime2 = new Date();
//   console.log("function execution time 2", endTime2 - startTime2);
//   console.log("strictEquals result 2", result2);
//   console.log("\n");
// }

function forEach() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    testArr1.push(true);
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  Arrays.forEach(testArr1, element => { element + "tree frog" });
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("forEach result testArr1", testArr1[0]);

  // for (var i = 0; i < 50000; i++) {
  //   testArr2.push(false);
  // }
  //
  // var counter2 = 0;
  // var startTime2 = new Date();
  // Arrays.forEach(testArr2, element => { return element = element + "ground frog" });
  // var endTime2 = new Date();
  // console.log("function execution time 2", endTime2 - startTime2);
  // console.log("forEach result testArr2", testArr2[0]);
  // console.log("\n");
}

function findFirst() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    if (i % 1000 === 0) {testArr1.push(false);} else {testArr1.push(true);}
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.findFirst(testArr1, false);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("findFirst result result", result);
  console.log("\n");
}

function findAll() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    if (i % 10000 === 0) {testArr1.push(false);} else {testArr1.push(true);}
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.findAll(testArr1, false);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("findAll result result", result);
  console.log("\n");
}

function map() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    if (i % 10000 === 0) {testArr1.push(false);} else {testArr1.push(true);}
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.map(testArr1, element => element + "frog");
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("findAll result result", result[0]);
  console.log("\n");
}

function copy() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000000; i++) {
    if (i % 10000 === 0) {testArr1.push(false);} else {testArr1.push(true);}
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.copy(testArr1);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("copy result result", testArr1[0] + " " +  result[0]);
  console.log("\n");
}

// call functions
// count();
// isArray();
// isEmpty();
// equal(); // not working
// strictEquals(); // not working
forEach();
// findFirst();
// findAll();
// map();
// copy();
