#include <nan.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace Nan;
using namespace v8;

void buffer_delete_callback(char* data, void* the_vector)
{
	delete reinterpret_cast<vector<unsigned char> *> (the_vector);
}

NAN_METHOD(Sum)
{
    unsigned int nrOne = info[0]->Uint32Value();
    unsigned int nrDwo = info[1]->Uint32Value();

	//
	// 	3.	allocate the vector on the heap because we are building a buffer
	// 		out of it's data to return to Node - and don't want to allow
	// 		it to go out of scope until the buffer does (
	// 		see buffer_delete_callback).
	//
	std::vector<unsigned char> * vBuffer = new vector<unsigned char>();

	vBuffer->push_back(nrOne + nrDwo);

	//
	//	5.	Sending the buffer that we created using the vector type to NodeJS
	//		So we can use use the data as is in NodeJS.
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

NAN_MODULE_INIT(Init) {

	Nan::Set(
		target,
		New<String>("sum").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(Sum)).ToLocalChecked()
	);

}

NODE_MODULE(basic_nan, Init)