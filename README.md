# NodeJS to C through C++

Using C or C++ for that mater in NodeJS is more of a edge case then daily life. But I had to learn this trick the hard way. I think over all I spent 3 weeks to figure everything out. Sadly there is very little documentation and knowledge on the Internet and decided to put in one place everything that I learned while focusing on the most simple example possible, so you can focus on how to send and receive data to C/C++ and NodeJS. Once you'll understand this concept you'll be able to write your own low level code or take advantage of faster libraries to process your specific data.

# Quick ground rules

Buffers mind are the simplest way to communicate between the two worlds. You just crate a blob of data that can be sent through any means of communication, and on the other end you can integrate it however you want. You are not sending a specific type, that you then need to match at the other end.

And since buffers are just dumps of raw bytes, any language will be able to handle them. The steps to create a successful app:

1. prepare a buffer in NodeJS,
1. send the buffer to C++ using a function exposed to NodeJS in C++,
1. access the buffer and save it in a variable of the right type,
1. do something with the data,
1. send the computed result back to NodeJS

# WARNING: The V8 API is constantly changing

V8 is the environment used by NodeJS to process JavaScript files. This environment is written in C++, therefore we can use C++ in our project 🛎. The downside of V8 is that Google have a very poor documentation for it, and to make it even worst a new version of V8 won't necessarily be compatible with the previous one.

That is why we have to hug 🤗 the hard working team of the Nan module for NodeJS, which basically wraps V8 in a consistent API, thus making our life much easier.

# How to use this repository

This repo has a bunch of directories containing fully working code showcasing how to one thing only. With this approach you can more easily see the differences how to handle different situations.

Each directory has its own README.md file explaining how to run the project and possibly additional informations about some caveats to be aware off.

# The book that made me understand

An important aspect of learning to use C libraries with NodeJS was the book “C++ and Node.js Integration.” - by Scott Frees, Ph.D. If you want take this subject seriously, you should definitely check this book out. It talks in more detail about more stuff that this article can cover. What I'm writing is more of a template, a reminder of what I learned. It should help you get started, but if you would like to go deeper that book is fantastic.

# To sum it all up

This is another article in a series of mine that tries to demystify something that seams to be hard, but in true honesty the way other developer explains something leves a lot to desire. Not to mention the little information that is out there.

If you like my approach, please consider giving this repo a 🌟.

Also check out my GitHub account, where I have other articles and apps that you might find interesting.