Project 1: Tokenizer
====================
To run the code go to shell and do ./token.

Tokenize and add_history are the two longest an dmost confusing of the
methods.

Tokenize takes a string and finds number of words in the string, then
allocates memory for that many words. Then it finds the end of the first word with word
terminator. From there it calculates the length of the entire string and the
length of the string starting from the end of the first word, then subtracts
the latter from the former which give us the length of the word we are about
to tokenize. After that we send the original string and the length of the word
to copy_str to get back a pointer to dynamically allocated memory that
contains the word. We then place the pointer into the allocated memory, and
set the pointer we got from our word terminator to be our new string then we
move it one space forward to reach the next word in the original string. This
is all done in a loop until all words have been tokeninzed and added to the
allocated memory.

add_history takes our list and a string. Firstly, the code makes a dynamically
allocated copy of the given string, then makes a new Item where that copy is
placed. If the list is empty that Item becomes the root node, other wise we
iterate through the list to find the end of the list and add it there.

The rest of the methods are rather simple and self-explanitory so i won't be
gooing over them. 
