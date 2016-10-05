'use strict';

//
//	Load our C++ app as a module
//
let addon = require('./build/Release/integer');

//
//	Create two variables as buffers
//
let nrOne = new Buffer("1");
let nrTwo = new Buffer("10");

//
//	Call the C++ function with our numbers, and store the result in a new
//	variable
//
let sum = addon.sum(nrOne, nrTwo);

//
//	Display the result of the C++ calculation
//
console.log("The sum of %s and %s is %s: ", nrOne, nrTwo, sum.readIntLE());