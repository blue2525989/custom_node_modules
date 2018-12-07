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
  console.log("\n");

  console.log("\n");
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
  console.log("\n");

  console.log("\n");
  var testArr2 = [];
  var startTime2 = new Date();
  var result2 = Arrays.isEmpty(testArr2);
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("isEmpty result 2", result2);
  console.log("\n");
}

function equal() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    testArr1.push(true);
  }

  console.log("\n");
  var startTime = new Date();
  var result = Arrays.equals(testArr1, testArr2);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("equal result", result);
  console.log("\n");

  for (var i = 0; i < 50000; i++) {
    if (i < 10)
    {
      testArr2.push(true);
    }
    else
    {
      testArr2.push(1);
    }
  }

  console.log("\n");
  var startTime2 = new Date();
  var result2 = Arrays.equals(testArr1, testArr2);
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("equal result 2", result2);
  console.log("\n");
}

function strictEquals() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    testArr1.push(true);
  }

  console.log("\n");
  var startTime = new Date();
  var result = Arrays.strictEquals(testArr1, testArr2);
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("strictEquals result", result);
  console.log("\n");

  for (var i = 0; i < 50000; i++) {
    testArr2.push(1);
  }

  console.log("\n");
  var startTime2 = new Date();
  var result2 = Arrays.strictEquals(testArr1, testArr2);
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("strictEquals result 2", result2);
  console.log("\n");
}

function forEach() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50000; i++) {
    testArr1.push(true);
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  Arrays.forEach(testArr1, element => {/*console.log(counter1++);*/ return element;});
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("forEach result testArr1", testArr1[0]);
  console.log("\n");

  for (var i = 0; i < 50000; i++) {
    testArr2.push(false);
  }
  //
  console.log("\n");
  var counter2 = 0;
  var startTime2 = new Date();
  var result2 = Arrays.forEach(testArr2, element => {element = element});
  var endTime2 = new Date();
  console.log("function execution time 2", endTime2 - startTime2);
  console.log("forEach result testArr2", testArr2[0]);
  console.log("\n");
}

// call functions
count();
isArray();
isEmpty();
equal();
strictEquals();
forEach();
