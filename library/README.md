# Working with strings

This example is focused on showcasing how to use a C library inside C++ and basically use the C++ environment as a proxy.

# How to run the example

First of all you need to install `Nan` and `Node-gyp`. To do so, you have to type in the console `npm install`. Then just type `npm start`. Check the `package.json` file to learn about what the last command does.

# Issues that you need to be aware of

If you take a closer look at content of this folder you will see that there are two `david_sum.h` files. One hear, and the other in the `c_libarary` folder. The content of those file is different. The header linked in the C++ file points to the `.h` file with the method wrapped in `extern "C"`.

`extern` is crucial to allow C++ to load C functions after decoration ([name mangling](https://en.wikipedia.org/wiki/Name_mangling)), since our C library is in a compiled form.

This example was build in a way to mimic a real life situation, where you'll get a compiled library and a header file. In this case you'll have to open the header file, and wrap each method with:

```C
extern "C"
{
	void function_name();
}
```

To let the C++ compiler know how to handle name decoration.