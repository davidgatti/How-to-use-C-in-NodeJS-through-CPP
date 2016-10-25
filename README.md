# NodeJS to C through C++

Using C or C++ for that mater in NodeJS is more of a edge case then daily life. But I had to learn this trick the hard way. I think over all I spent 3 weeks to figure everything out. Sadly there is very little documentation and knowledge on the Internet and decided to put in one place everything that I learned while focusing on the most simple example possible, so you can focus on how to send and receive data to C/C++ and NodeJS. Once you'll understand this concept you'll be able to write your own low level code or take advantage of faster libraries to process your specific data.

# Quick ground rules

Buffers mind are the simplest way to communicate between the two worlds. You just crate a blob of data that can be sent through any means of communication, and on the other end you can integrate it however you want. You are not sending a specific type, that you then need to match at the other end.

And since buffers are just dumps of raw bytes, any language will be able to handle them. The steps to create a successful app:

1. First, lets prepare a buffer in NodeJS
1. Second, lets send the buffer to C++
1. Thirty, lets process the buffer in C++
1. Forth, lets convert it so C can handle it.
1. Fifth, lets do something with the data
1. Sixth, lets send the data back to NodeJS.

# WARNING: The V8 API is constantly changing

V8 is the environment used by NodeJS to process JavaScript files. This environment is written in C++, therefore we can use C++ in our project 🛎. The downside of V8 is that Google have a very poor documentation for it, and to make it even worst a new version of V8 won't necessarily be compatible with the previous one.

That is why we have to hug 🤗 the hard working team of the Nan module for NodeJS, which basically wraps V8 in a consistent API, thus making our life much easier.

# The book that made me understand

I know this is going to sound weird but part of me that made me want write this article is to be able and spread the word about the book “C++ and Node.js Integration.” - by Scott Frees, Ph.D.

As he writes in his book, the information about NodeJS and C++ is so scarce on the internet that he took the time to learn everything that there was about this topic, and turn it in to a book, and I command him for that.

Why should you buy this book after me writing about basically how to work with NodeJS and C++? Because I only talk about buffer, to me they are the most flexible form, and I was happy to master this. But there is a lot more to it. In the book you can learn about

- how to send object,
- how to write async code
- and much more.

Honestly I could not recommend this book more.

# To sum it all up

This is another article in a series of mine that tries to demystify something that seams hard and show it for what it is. A simple way of doing something but which in this case had almost no information to learn how it really works. And if you like my approach, please consider giving this repo a 🌟.

Also check out my GitHub account, where I have other articles and apps that you might find interesting.