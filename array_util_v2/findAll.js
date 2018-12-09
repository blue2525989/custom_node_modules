var Arrays = require('bindings')('array_util');
var util = require('util');

function findAllObj() {
  var testArr1 = []
  var testArr2 = [];
  for (var i = 0; i < 50; i++) {
    if (i % 2 === 0)
    {
      testArr1.push({name: "tim buck two", msg: "Grind the bones"});
    }
    else
    {
      testArr1.push({name: "tim buck three", msg: "Grind the bones"});
    }
  }

// {name: "tim buck three", msg: "Of the english man"}

  console.log("\n");
  var counter1 = 0;
  var startTime = new Date();
  var result = Arrays.findAll(testArr1, element => {console.log(element)});
  var endTime = new Date();
  console.log("function execution time", endTime - startTime);
  console.log("findall result", util.inspect(result));
  console.log("\n");
}
// call functions
findAllObj();
