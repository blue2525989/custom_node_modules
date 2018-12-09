var log = require("./build/Release/printer.node");

// this does work, but prints before terminal prompt
var logger = new log.Log();
logger.info("this is my logger init");

// this does work, but prints before terminal prompt
function printTest1() {
  var logger = new log.Log();
  logger.info("this is my logger info");
  logger.info({"key1": "value 1", "key2": "value 2"});
  logger.info(32424);
}

function printTest2() {
  var logger = new log.Log();
  logger.debug("this is my logger debug");
}

function printTest3() {
  var logger = new log.Log();
  logger.error("this is my logger error");
}

function getLogLevel1() {
  var logger = new log.Log();
  logger.error("setting my log level");
  var level = logger.getLogLevel();
  logger.error(level);
}


// main :P
// printTest1();
// printTest2();
// printTest3();
getLogLevel1();
