#include <nan.h>
#include <iostream>

using namespace std;
using namespace Nan;
using namespace v8;

//
//	The function that we are going to call from NodeJS
//
NAN_METHOD(Combine)
{
	//
	//	1.	save the buffers that I passed from NodeJS in to local variables
	//
	char* partOne = (char*) node::Buffer::Data(info[0]->ToObject());
	char* partTwo = (char*) node::Buffer::Data(info[1]->ToObject());

	//
	//	2.	Count the total length of those chars, plus 1 for the extra space.
	//
	//		IMPORTANT: 	figuring out the length of a char is easy since it is
	//					terminated with a 0. Any other type should be checked
	//					for byte length on the NodeJS side, since it is easier
	//					doing it there. Then just pass the expected length hear.
	//
	uint8_t length = strlen(partOne) + strlen(partTwo) + 1;

	//
	//	3.	The char variable that will hold the concatenated ASCII string
	//
	char* str = new char[length];

	//
	//	4.	Combine the variables in to one single string
	//
  	strcpy(str, partOne);
  	strcat(str, " ");
  	strcat(str, partTwo);

	//
	//	->	Send the buffer back to NodeJS with the result of our calculation.
	//
	info
	.GetReturnValue()
	.Set(
		NewBuffer(str, length)
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
		New<String>("combine").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(Combine)).ToLocalChecked()
	);
}

//
//	Load the constructor
//
NODE_MODULE(basic_nan, Init)