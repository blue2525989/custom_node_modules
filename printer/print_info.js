var log = require("./build/Release/printer.node");

// this does work, but prints before terminal prompt
var logger = new log.Log();
logger.info("this is my logger");

// this does work, but prints before terminal prompt
function printTest1() {
  var logger = new log.Log();
  logger.info("this is my logger");
}

function printTest2() {
  var logger = new log.Log();
  logger.debug("this is my logger");
}

function printTest3() {
  var logger = new log.Log();
  logger.error("this is my logger");
}

function getLogLevel1() {
  var logger = new log.Log();
  logger.error("setting ym log level");
  var level = logger.getLogLevel();
  // logger.error(level);
  // logger.error(logger);
  logger.error(logger.logLevel_);
}


// main :P
printTest1();
printTest2();
printTest3();
getLogLevel1();
