# NodeJS to C through C++

Using C or C++ in NodeJS is more of an edge case than daily life. But I decided to put down what I learned because there is little information on the Internet about this topic. My goal is to focus on simple example, so you can focus on how to send data to and receive data from C/C++ and NodeJS. Once you understand this concept, you'll be able to write your own low-level code or take advantage of faster libraries to process your specific information.

# Quick ground rules

Keep in mind that buffers are the simplest way to communicate between the two worlds. You just create a blob of data that can be sent through any means of communication, and on the other end, you can integrate it however you want. You are not sending a specific type that you then need to match at the other end.

And since buffers are just dumps of raw bytes, any language will be able to handle them. The steps to create a successful app:

1. Prepare a buffer in NodeJS
2. Send the buffer to C++ using a function exposed to NodeJS from C++
3. Access the buffer and save it in a variable of the right type
4. Do something with the data
5. Send the computed result back to NodeJS

# WARNING: The V8 API is constantly changing

V8 is the environment used by NodeJS to process JavaScript files. This environment is written in C++; therefore, we can use C++ in our project 🛎. The downside of V8 is that Google has very poor documentation for it, and to make it even worse, a new version of V8 won't necessarily be compatible with the previous one.

That's why we have to hug 🤗 the hard working team of the [Nan](https://github.com/nodejs/nan) module for NodeJS, which basically wraps V8 in a consistent API, thus making our life much easier.

# How to use this repository

This repo has a bunch of directories containing fully working code that showcases how to do one thing only. With this approach, you can more easily see how to handle different situations.

Each directory has its own README.md file explaining how to run the project and, possibly, additional information about some caveats to be aware of.

# The book that made me understand

The book [C++ and Node.js Integration by Scott Frees, Ph.D](https://scottfrees.com/ebooks/nodecpp/) was an important aspect of learning to use C libraries with NodeJS. If you want take this subject seriously, you should definitely check this book out. It talks in greater detail about more stuff than this article can cover. What I'm writing is more of a template, a reminder of what I learned. It should help you get started, but if you would like to go deeper, that book is fantastic.

# To sum it all up

This article is part of my series that tries to demystify topics that are deemed hard, but where in truth they are just poorly explained. If you like my approach, please consider giving this repo a 🌟.

Also check out my [GitHub](https://github.com/davidgatti) account, where I have other articles and apps that you might find interesting.