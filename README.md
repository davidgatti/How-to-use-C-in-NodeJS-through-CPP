# NodeJS to C through C++

I’m excited about this article because it is a thought only because there is very limited information o the net and I know it will help anyone trying to figure out how to communicate between NodeJS and C.

I know that this situation is very rare but when one day you might work at a company with some legacy C libraries that you have to use, and there is no dancing around it. I had a situation like this, I went through the pain to understand this part of NodeJS, and I want to live a trail behind for others to follow.

# Quick ground rules

NodeJS communicates to C++ and not C directly. Meaning there is a big issue with types from NodeJS to C++ and from C++ to C. The C language is dead simple, and higher you go the more types you are going to get that are incompatible. The problem is not even interpretation of the data, for example Signed Integer vs. Unsigned.

Buffers, the simplest way to communicate

Yes, in my mind this is the simplest way you can possibly communicate between different languages, because you crate a blob of data that can be sent through any means of communication, and on the other end you can integrate it however you want. You are not sending a specific type, that you then need to match at the other end. And Integer in Javascript is completely different form one in C++.

And since buffers are just dumps of raw bytes, any language will be able to handle them.

## First, lets prepare a buffer in NodeJS

## Second, lets send the buffer to C++

## Thirty, lets process the buffer in C++

## Forth, lets convert it so C can handle it.

## Fifth, lets do something with the data

## Sixth, lets send the data back to NodeJS.

# WARNING: The V8 API is constantly changing

One thing to consider when deciding to write a project using this approach is the ever changing API for V8, the engine that drives NodeJS. This means that if today something that you wrote, in the next or previous version might not work. This means you need to keep a constant eye on the NAN project and make sure to upgrade that module to make sure, that your code will keep work under newer or even older versions of NodeJS

# The book that made me understand

I know this is going to sound wierd but part of me that made me want write this article is to be able and spread the word about the book “C++ and Node.js Integration.” - by Scott Frees, Ph.D.

As he writes in his book, the information about NodeJS and C++ is so scarce on the internet that he took the time to learn everything that there was about this topic, and turn it in to a book, and I command him for that.

Why should you buy this book after me writing about basically how to work with NodeJS and C++? Because I only talk about buffer, to me they are the most flexible form, and I was happy to master this. But there is a lot more to it. In the book you can learn about

- how to send object,
- how to write async code
- and much more.

Honestly I could not recommend this book more.

# To sum it all up

This is another article in a series of mine that tries to demystify something that seams hard and show it for what it is. A simple way of doing something but which in this case had almost no information to learn how it really works. And if you like my approach, please consider giving this repo a 🌟.

Also check out my GitHub account, where I have other articles and apps that you might find interesting.