#ifndef HASH_TABLE
#define HASH_TABLE

#include <list>
#include <string>
#include <iostream>
#include <cctype>
#include <math.h>
#include <stdexcept>

class HashTable {
   public:
     HashTable ();
     /* Constructor that builds a hash table with 31 indices. */

     HashTable (int numIndices);
     /* Constructor builds a hash table with a given number of indices */

     ~HashTable ();

     void add (std::pair<std::string, int> new_item);
       /* adds new_item to the hashtable.  
          Conflicts should be resolved via chaining.
          You may use the STL list to accomplish this. 
          Throws an exception if the key is already 
          in the hashtable.*/

     const int& find (std::string key) const;
       /* returns the value with the associated key. 
          Throws an exception if the key is not in the
          hashtable. */

     void remove (std::string key);
       /* removes the element with the associated key. 
          Throws an exception if the key is not in the
          hashtable. */

     void update (std::pair<std::string, int> new_value);
       /* finds the item with the associated key, 
          and updates its value accordingly. 
          Throws an exception if the key is not in the
          hashtable. */
     void print ();
       /* Prints all values in hash table */

     int const & operator[](std::string str);
       /* returns the value with the associated key. 
          Throws an exception if the key is not in the
          hashtable. */

 private:
    std::list<std::pair<std::string, int> >* data;
    int numberOfElements;
    int numberOfIndices;

    long long hash (const std::string &key) const;
      /* first translate string to a long long
         29^(n-1) * p(n-1)] + ... + [29^2 * p2] + [29 * p1] + [p0]
         p0 = last letter of string, p(n-1) = first letter of string
         each letter should eval to int 0-25; a=0, b=1, ..., z = 25
         mod entire result by size of hashtable */

    bool isMaxLoad ();
      /* numberOfElements / numberOfIndices = loadFacotr
         returns a boolean based on whether or not the load factor
         has exceeded it's limit of 1 */

    void resize ();
      /* Resizes the hash table to have (2m+1) indices
         m being the number of indices that the hash
         table contained before resize */

    int enumerateChar (char c) const;
      /* Converts a char to appropriate interger value
         where a=0, b=1, ..., z=25*/
};


#endif