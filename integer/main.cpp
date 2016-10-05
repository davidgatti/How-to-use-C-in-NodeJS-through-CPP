#include <nan.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace Nan;
using namespace v8;

//
//	Function needed to remove the buffer from memory so we don't create leeks
//
void buffer_delete_callback(char* data, void* the_vector)
{
	delete reinterpret_cast<vector<unsigned char> *> (the_vector);
}

//
//	The function that we are going to call from NodeJS
//
NAN_METHOD(Sum)
{
	//
	//	1. 	Store the values passed by NodeJS by accessing the info array.
	//		Since we are sending buffers, we specify of what type the
	//		values are.
	//
    unsigned int nrOne = info[0]->Uint32Value();
    unsigned int nrDwo = info[1]->Uint32Value();

	//
	// 	2.	Allocate the vector on the heap because we are building a buffer
	// 		out of it's data to return to NodeJS.
	//
	std::vector<unsigned char> * vBuffer = new vector<unsigned char>();

	//
	//	3. 	Sum our two numbers and push the result in to the buffer of unsigned
	//		char, which in our case will consist of positive numbers.
	//
	vBuffer->push_back(nrOne + nrDwo);

	//
	//	4.	Send the buffer back to NodeJS with the result of our calculation.
	//
	info
	.GetReturnValue()
	.Set(
		NewBuffer(
		(char *) vBuffer->data(),
		vBuffer->size(),
		buffer_delete_callback,
		vBuffer)
	.ToLocalChecked());
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