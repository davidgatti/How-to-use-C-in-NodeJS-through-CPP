# Working with strings

This example is focused on showcasing how to send and receive strings between the two languages.

# If you are not fluent with C/C++

If you check the `.cpp` file you'll see that we create a `char` variable. If you come mainly from the JavaScript world you are probably thinking that `char == string`. And you'll be wrong. A `char` holds only one byte of information, meaning the max value is an integer of 255. Meaning you won't be able to pass all the UTF-8 characters. Since a UTF-8 char can take up to 6 bytes.

Make sure you work only with ASCII characters and everything will work without a problem. Otherwise you'll be staring at the screen and ingratiation your head for a long time 🤔 😅.

# How to run the example

First of all you need to install [Nan](https://github.com/nodejs/nan) and [Node-gyp](https://github.com/nodejs/node-gyp), and to do so, you have to type in the console `npm install`, then just type `npm start`. Check the `package.json` file to learn about what the last command does.