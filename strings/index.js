'use strict';

//
//	Load our C++ app as a module
//
let addon = require('./build/Release/strings');

//
//	Create two variables as buffers
//
let partOne = new Buffer("David");
let partTwo = new Buffer("Gatti");

//
//	Call the C++ function, pass our variables, and store the result in a new
//	variable
//
let combined = addon.combine(partOne, partTwo);

//
//	Display the result of the C++ calculation
//
console.log("By combining %s and %s we get: %s", partOne, partTwo, combined.toString());