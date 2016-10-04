'use strict';

let addon = require('./build/Release/integer');

let nrOne = new Buffer("1");
let nrTwo = new Buffer("2");

let sum = addon.sum(nrOne, nrTwo);

console.log("The sum of %s and %s is %s: ", nrOne, nrTwo, parseInt(sum.toString('hex')));