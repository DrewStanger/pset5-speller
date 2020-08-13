# pset5-speller
NOTE: Copying this data and using it for your submission will breach the academic honesty https://cs50.harvard.edu/x/2020/honesty/ policy of CS50. Make sure you learn the material and provide the solution by youself. It's worth it!!

This is my solution of the CS50 speller problem set, using C. https://cs50.harvard.edu/x/2020/psets/5/speller/ This problem set required implemnetation of a program which spell-checks a file (from a list of words, i.e. the dictionaries provided by CS50).

This was produced as a part of CS50 - Introduction to Computer Science. Uploading of my solution to Github is considered to be reasonable regarding the academic honesty policy. (https://www.reddit.com/r/cs50/comments/63235w/is_this_reasonable/)

This problem required the implementation of the following functions (all within dictionary.c);
- load.
- hash.
- size.
- check.
- unload.

To enhance the speed at which words in a provided text could be spell checked against the dictionaries;
1. the dictionaries were opened in the function load and added into a character array.
2. the character arrawy consisted of a linked lists, so each word was loaded into the linked list and then hashed through using the hash function, which provided a hash value.
3. size returns the number of nodes/words added through increasing at each iteration of the while loop contained within the load function.
4. the load function checks each node against each word in the hash table with the corrosponding index to return true if it is present.
5. unload frees all of the data contained within the hash table by iterating through the hash table.

Note* There are additional file ommited from this repository which are the dicitionaries and sample texts, additionally there is a makefile which compiles the speller and dicitonary files.
