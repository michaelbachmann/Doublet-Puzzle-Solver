#ifndef MIN_HEAP
#define MIN_HEAP
#include "hash_table.h"
#include <stdexcept>
#include <iostream>
#include <vector>

class MinHeap {
   public:
     MinHeap (int d);
     /* Constructor that builds a d-ary Min Heap
        This should work for any d >= 2,
        but doesn't have to do anything for smaller d.*/

     ~MinHeap ();

     void add (std::string item, int priority);
       /* adds the item to the heap, with the given priority. */

     const std::string & peek () const;
       /* returns the element with smallest priority.  If
          multiple items have the smallest priority, it returns
          the string which comes first alphabetically.
          Throws an exception if the heap is empty. */

     void remove ();
       /* removes the element with smallest priority.  If
          multiple items have the smallest priority, it removes
          the string which comes first alphabetically.
          Throws an exception if the heap is empty. */

     void update (std::string item, int priority);
       /* updates the priority for the specified element. 
          Throws an exception if the item is not in the heap. */  

     bool isEmpty ();
       /* returns true iff there are no elements on the heap. */

     void printHeap(int option);
       /* Print's the heap with levels if you pass 0, prints it as an array if you pass 1, defaults to 1 */

     void printChildrenOf(int index);
       /* Print's children of index */

     bool is_in_heap(std::string str);
       /* Returns true if the item is in the heap and false if not */

 private:
    unsigned int d_ary;

    HashTable* map;
      /* Maps a string to the index it is currently located at in the heap */

    std::vector<std::pair<std::string, int> > items_;
      /* This is how we are storing our heap */

    void trickleUp(std::string str, int index);
      /* Add helper function */

    void heapify(int index);
      /* Remove helper function */

    int getParentIndex(int index);
      /* Takes in an index and returns the parent index*/

    int getFirstChildIndex(int index);
      /* Takes in an index and returns the index of the first child */

    int getMinChild(int parent);
      /* Gets the smallest child of a parent in a d-ary heap */

    void swap(int index, int p_index);
      /* Swaps values in the vector, doesn't affect hash table */
};

#endif