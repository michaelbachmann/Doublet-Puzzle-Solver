#Doublet Puzzle Solver
An from scratch implementation of a hash table, a priority queue (implemented with a min heap), and the A* search algorithm to find the optimal solution for a given word ladder.

##Background Information
The Doublet Puzzle (also known as Word Ladders, Laddergrams and change-the-word puzzles) was not only the author of _Alice's Adventures in Wonderland_ and _Through the Look-Glass_ but also a mathematician one of the greatest inventers of puzzles. One of his most famous puzzles was coined the doublet. The basic idea of the puzzle is to take a `start word` and an `end word` and transform the start word into the end word by changing one letter at a tie. So for example...

> **Start Word: ** HEAD - **End Word: ** TAIL
>
1. Heal (Change "d" of head to "l")
> 2. Teal (Change "h" of heal to "t")
> 3. Tell (Change "a" of Teal to "l")
> 4. Tall (Change "e" of Tell to "l")
> 5.  **TAIL** (Change first "l" of tail to "i")

To learn more about the puzzle see [this article](https://www.psychologytoday.com/blog/brain-workout/200908/the-doublet-puzzle-masterpiece-the-pen-lewis-carroll). My explanation was just a brief summary of that articles examplation. Also see the [Wikipedia](https://en.wikipedia.org/wiki/Word_ladder) for more information.

## Notes
**_Note:_** To simply use the puzzle solver follow the `A* Doublet Puzzle Solver` directions. The `Hashtable` and `MinHeap` can aso be used seperately for other programs but is currently not templated. Follow the compiliation directions for each of those respectively if you wish to use them.

**_Known Issues:_** Things I'll work on when I have the time.
* Adding multiple items of the same string several times causes strange behavior.
* If A* cannot find a path the program terminates with an uncaught exception. Easy fix, will take care of soon.

## Compiliation Steps
### A* Doublet Puzzle Solver

**_To execute the program..._**

1. First compile the program by running `make`

2. Run the program with `bin/doublet start_word goal_word /path/to/dictionary.txt`, i.e. `bin/doublet river sweep data/AStarTestFile.txt`

3. Rejoice.


###Hashtable

**_To use the hash table in your program..._**

1. Compile the hash_table by running `make bin/hashtable.o`

2. Include the `hash_table.h` found in the lib directory in your main program.

3. Create a hash table such as `HashTable map;`

4. See `hash_table.h` for function prototypes.

###D-ary Min Heap

**_To use the d-ary min heap in your program..._**

1. Compile the MinHeap by running `make bin/minheap.o`

2. Include the `min_heap.h` found in the lib directory in your main program.

3. Create a d-ary min heap with `MinHeap priority_queue(d);` where d is the d-ary value.

4. See `min_heap.h` for function prototypes.