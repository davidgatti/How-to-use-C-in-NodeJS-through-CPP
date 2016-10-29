# Our custom C library

This is our super basic library that have one function that takes two numbers and sums them together. The project is broken down in the following way:

- david_sum.c: the function that will do the processing
- david_sum.h: the header file
- main.c: an example that uses the function to show that the library works in C

To compile the library and the main app, you just have to type in the console `make`. Then if you list the content of the folder you'll see the library with the main app, that if you run, it will output in the terminal the result of the addition. Proving that everything works.

Once this part is done, you don't have to move the compiled library from this directory because it is going to be linked in the `binding.gyp` file directly to hear.