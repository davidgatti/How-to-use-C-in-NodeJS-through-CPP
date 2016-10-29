#include <nan.h>
#include <iostream>
#include "david_sum.h"

using namespace std;
using namespace Nan;
using namespace v8;

//
//	The function that we are going to call from NodeJS
//
NAN_METHOD(Sum)
{
	//
	//	1.	Save the buffers that I passed from NodeJS in to local variables
	//
	unsigned int nrOne = info[0]->Uint32Value();
	unsigned int nrDwo = info[1]->Uint32Value();

	//
	//	2.	Sum the two numbers together
	//
	uint32_t sum = david_sum(nrOne, nrDwo);

	//
	//	->	Send the buffer back to NodeJS with the result of our calculation.
	//
	info
	.GetReturnValue()
	.Set(
		Nan::New<Uint32>(sum));
}

//
//	The constructor
//
NAN_MODULE_INIT(Init)
{
	//
	//	Expose the method or methods to NodeJS
	//
	Nan::Set(
		target,
		New<String>("sum").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(Sum)).ToLocalChecked()
	);
}

//
//	Load the constructor
//
NODE_MODULE(basic_nan, Init)