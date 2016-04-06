#include "../lib/min_heap.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	MinHeap priorityQueue(2);
	priorityQueue.add("hover",20);
	priorityQueue.add("lover",20);
	priorityQueue.add("rover",20);
	priorityQueue.add("dover",20);
	priorityQueue.add("river",20);
	priorityQueue.add("aover",20);
	priorityQueue.add("aoier",20);
	priorityQueue.add("aoaer",20);
	priorityQueue.add("aober",20);
	priorityQueue.add("aiier",20);

	priorityQueue.printHeap();


	// priorityQueue.add("1",7);
	// priorityQueue.add("5",18);
	// priorityQueue.add("3",9);
	// priorityQueue.add("4",19);
	// priorityQueue.add("2",35);
	// priorityQueue.add("6",14);
	// priorityQueue.add("7",10);
	// priorityQueue.add("8",28);
	// priorityQueue.add("9",39);
	// priorityQueue.add("10",36);
	// priorityQueue.add("11",43);
	// priorityQueue.add("12",16);
	// priorityQueue.add("13",17);
	// priorityQueue.add("14",23);

	// priorityQueue.printHeap();
	// priorityQueue.remove();
	// priorityQueue.remove();

	// // priorityQueue.printHeap();
	// priorityQueue.update("3",18);
	// priorityQueue.printHeap();

	// priorityQueue.remove();
	// priorityQueue.printHeap();
	// priorityQueue.remove();



	// priorityQueue.printChildrenOf(1);
	// priorityQueue.printChildrenOf(2);



	/* code */
	return 0;
}