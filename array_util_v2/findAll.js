var Arrays = require('bindings')('array_util');
var util = require('util');

function findAllObj() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 5000000; i++) {
    if (i % 10000 === 0)
    {
      testArr1.push({name: "tim buck two", msg: "Grind the bones"});
    }
    else
    {
      testArr1.push({name: "tim buck three", msg: "Of the english man"});
    }
  }

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.findAll(testArr1, element => { element.name === "tim buck three" });
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("findall result result", util.inspect(testArr1[0]) + " " +  util.inspect(result));
  console.log("\n");
}

// function copyPrimiatives() {
//   var testArr1 = []
//   var testArr2 = [];
//   for (var i = 0; i < 5000000; i++) {
//     if (i % 10000 === 0)
//     {
//       testArr1.push(true);
//     }
//     else
//     {
//       testArr1.push(false);
//     }
//   }
//
//   console.log("\n");
//   var counter1 = 0;
//   var startTime = new Date();
//   var result = Arrays.copy(testArr1);
//   var endTime = new Date();
//   console.log("function execution time", endTime - startTime);
//   console.log("copy result result", util.inspect(testArr1[0]) + " " +  util.inspect(result[0]));
//   console.log("\n");
// }

// call functions
findAllObj();
// copyPrimiatives();
