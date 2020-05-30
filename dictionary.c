 // Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int TABLE_SIZE = 50000; //25 as 26 alphabet characters, could also implement first two letters, or math using all letters. Google some good ones.

// Hash table //set N to a higher number to capture data.
node *table[TABLE_SIZE];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //return true if found else return false.

    int index = hash(word);
    //make a cursor which points to the haeder
    node *cursor = table[index];
    //for loop to go through the linked list
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
      if (strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    //for  this hash get the lengh of the string then we will sum the value of the characters.
    unsigned int hashvalue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = (hashvalue * tolower(word[i])) % TABLE_SIZE;
    }
    return hashvalue;

}

int counter = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO - returns true if all data loaded into hash table, - false if there is an error.
    // Stores all data in a hash table, put words being with A in the A hash etc. use a hash  function to assign these to the relevant linked list.
    // Hash function, takes a word input, outputs a word corresponding to which bucket to store the word in index [0] will be A.
    // to add new data to hash table, allocate memory for nodes then add data to the node. EG -- node *n = malloc(sizeof(node)); this format copies words into the character array strcpy(n->word, "hello"); to set next pointer n->next = NULL;

    // OPEN DICTIONARY FILE
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }
    //READ STRINGS FROM FILE
    //wordlist character array
    //allocate memory
    char wordlist[LENGTH + 1];
  

    //while fscanf != EOF print the words into the character array word.

    while (fscanf(file, "%s", wordlist) != EOF)
    {

        //Keep track of how many nodes are being made

        counter++;

        //make new node
        node *newNode = malloc(sizeof(node));
        //check for null
        if (newNode == NULL)
        {
            return 1;
        }
        //initialize the new node
        strcpy(newNode->word, wordlist);
        newNode->next = NULL;
        //insert new node at head
        // printf("\n%s", wordlist);
        //add to hash table each element of the hashtable is a linked list!
        //if index X = NULL X points to newNode->word
        //if index != NULL newNode->word points to the old head of the list,
        int index = hash(wordlist);
        //if the index is not yet assigned, put the newest node at the head of it.
        //table[index] is the head node essentially?
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        //if the index is assigned we want to 1. point the newNode at the old node 2. point the index at the newNode->next
        else
        {
            //makes the next the new head
            newNode->next = table[index];
            //head points to the new node.
            table[index] = newNode;
        }
    
    }
    
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // to do
    // keep track of how many nodes have been added.
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // for each of the TABLE_SIZE buckets we must free the nodes.
    //make a cursor which points to the haeder
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        //
        cursor = table[i];
        while (cursor != NULL)
        {
           tmp = cursor;
            cursor = cursor->next;
           free(tmp);

        }
    }
    return true;
}
