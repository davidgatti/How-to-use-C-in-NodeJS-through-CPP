# Working with a library

This example is focused on showcasing how to use a C library inside C++ and basically use the C++ environment as a proxy.

# How to run the example

First go to the `c_libaryr` folder and compile the library, then come back hear and install [Nan](https://github.com/nodejs/nan) and [Node-gyp](https://github.com/nodejs/node-gyp). To do so, type in the console `npm install`. Then just type `npm start`. Check the `package.json` file to learn about what the last command does.

#Issues that you need to be aware of

## macOS != Linux

This is an important one. If you try to run this project on your Mac, it won't work because of saddle differences in how macOS manages libraries. If you want to find out more about this issue, Google: SIP (System Integrity Protection); you'll find many detailed explanations of this mode, also known as *rootless*.

The best environment for working with libraries is Linux.

## Extern

If you take a closer look at content of this folder, you will see that there are two `david_sum.h` files. One here, and the other in the c_libarary folder. The content of those files is different. The header linked in the C++ file points to the `.h` file, with the method wrapped in `extern "C"`.

extern is crucial for allowing C++ to load C functions after decoration ([name mangling](https://en.wikipedia.org/wiki/Name_mangling)), since our C library is in a compiled form.

This example was built to mimic a real life situation, where you'll get a compiled library and a header file. In this case, you'll have to open the header file, and wrap each method with:

```C
extern "C"
{
	void function_name();
}
```

To let the C++ compiler know how to handle name decoration.