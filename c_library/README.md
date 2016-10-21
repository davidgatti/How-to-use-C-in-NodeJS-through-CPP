# How to create a C library and dynamically link it

This is a super quick and basic tutorial to create a custom C library that we are going to use in our C++ code to be accessed through NodeJS. I decided to go this route instead of using something already on the market, because this way we can have a super simple library, that is dead simple to use, and we don't have to learn the whole API for a specific function just for testing.

## 1. Create the file with one method in it

The calc_mean.c file as you can see contain only the following code

```C
int sum(int a, int b) {
  return a + b;
}
```

## 2. Create a header file

To be able to use our custom function, we need to create a header file that is going to be imported in to the main code which will hold our logic. For example in our C++ file.

And again, the content of the `calc_mean.h` is super basic, just one line of code

```
int sum(int, int);
```

## 3. Create an object file out of the C file

Now that we have our custom function, we need to turn the source code in to an object file with the following command `gcc -c calc_sum.c -o calc_sum.o`.

## 4. Archive the object to make a static library

Now that we have our `.o` file we can use it to create the static library by using the `ar` command as follows: `ar rcs libsum.a calc_sum.o`.

## 5. Use the library

Before we go to the C++ side of the project, lets create a `main.c` file, and see if our library will work with the following logic.

```
#include <stdio.h>
#include "calc_sum.h"

int main() {

  int n1, n2, x;
  n1 = 5;
  n2 = 7;

  x  = sum(v1, v2);

  printf("The sum of %d and %d is %d\n", n1, n2, x);

  return 0;
}
```

## 6. Compile everything

To compile the code with the library, you have to tell the compiler the name of the library that you want to link. You would think that the header file should help the compiler figure out what we want to add to the project, but no, you have to specificlaly tell the compiler what you want because this way, you can easily switch version of the library, or use another one with similar function name.

To do so, you run the compile the following way: `gcc main.c -o dynamically_linked -L. -lsum`.