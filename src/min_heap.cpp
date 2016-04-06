#include "../lib/min_heap.h"

MinHeap::MinHeap (int d) {
	d_ary = d;
	map = new HashTable;
}


MinHeap::~MinHeap () {
	delete map;
}

bool MinHeap::is_in_heap(std::string str) {
	try {
		map->find(str);
		return true;
	} catch (std::out_of_range) {
		return false;
	}
}

void MinHeap::add (std::string item, int priority) {
	try {
		if (items_[map->find(item)].second < priority)
			update(item,priority);
	} catch (std::out_of_range){};

	items_.push_back(std::make_pair(item,priority));  // append pair to heap
	map->add(std::make_pair(item,items_.size()-1));	  // store it's location in our hash table
	if (items_.size() != 1)
		trickleUp(item, items_.size()-1);						  // trickle it's bitch ass up
}


const std::string & MinHeap::peek () const {
	if (items_.empty()) throw std::out_of_range("Cannot Peek, Heap Empty");
	return (items_[0].first);
}


void MinHeap::remove () {
	map->remove(items_[0].first);  // remove from map
	items_[0] = items_.back();	  // take last item and put in first position of heap
	items_.pop_back();			  // delete last item
	heapify(0);					  // heapify that shit
}

void MinHeap::update (std::string item, int priority) {
	int index = map->find(item);
	items_[index].second = priority;
	if ( items_.size() == 0 ) throw std::out_of_range("Cannnot Update, Heap Empty");

	if ( items_.size() == 1 ) // if only item don't move
		return;
	else if ( items_[getParentIndex(index)].second >=  priority )  // if parent is greater then trickle up
		trickleUp(items_[index].first,index);
	else {
		try { // check for children
			items_.at(getFirstChildIndex(index)); // if there are children
			if ( items_[getMinChild(index)].second < priority )  // if the smallest child has a better priority
				heapify(index);
		} catch(std::out_of_range) {}
	}

}

bool MinHeap::isEmpty () {
	return items_.empty();
}

void MinHeap::heapify(int index) {
	// check for leaf nodes
	try {
		items_.at(getFirstChildIndex(index));		
	}
	catch(std::out_of_range) {
		return;
	}

	int min_child = getMinChild(index);
	if (items_[index].second > items_[min_child].second) {
		swap(index,min_child);
		heapify(min_child);
	}

}

int MinHeap::getMinChild(int index) {
	index = getFirstChildIndex(index);
	int min_child = index;
	for (unsigned int i = index; ((i < d_ary+index) && (i <= items_.size()-1)); ++i) {
		if (items_[i].second < items_[min_child].second)
			min_child = i;
		else if ( items_[i].second == items_[min_child].second ) {
			if ( items_[i].first < items_[min_child].first )
				min_child = i;
		}
	}
	return min_child;
}

void MinHeap::trickleUp(std::string str, int index) {
	if (index == 0) return;

	int parentIndex = getParentIndex(index);

	if ( items_[index].second < items_[ parentIndex ].second ) {  // if parent is smaller
		swap(index,getParentIndex(index));  // swap the values in our heap
		trickleUp(items_[getParentIndex(index)].first,getParentIndex(index));  // keep on keeping on
	}
	else if ( items_[index].second == items_[ parentIndex ].second ) {
		if ( items_[index].first < items_[parentIndex].first )
			swap(index,getParentIndex(index));  // swap the values in our heap
		trickleUp(items_[getParentIndex(index)].first,getParentIndex(index));  // keep on keeping on

	}
}


int MinHeap::getParentIndex(int index) {
	if ( index == 0 ) throw std::out_of_range("Node has no parent");
	return ( ( index - 1 ) / d_ary );
}


int MinHeap::getFirstChildIndex(int index) {
	if (( ( index * d_ary ) + 1 ) > items_.size()-1) throw std::out_of_range("Node has no children");
	return ( ( index * d_ary ) + 1 );
}


void MinHeap::swap(int index, int p_index) {
	map->update(std::make_pair(items_[index].first, p_index));  // str should now be mapped to its parents index
	map->update(std::make_pair(items_[p_index].first, index));  // the parents index should now be mapped to n

	std::pair<std::string, int> temp = items_[index];
	items_[index] = items_[p_index];
	items_[p_index] = temp;
}

void MinHeap::printHeap(int option) {
	int count = 0;
	int print_type = 1;

	if ((option == 0) || (option == 1))
		print_type = option;

	std::cout << "<====== Priority Queue ======>\n";
	if (print_type == 0) {
		int nodesInLevel = 1;
		int level = 0;
		std::cout << "<----- Levels Visualized ---->\n";
		for (std::vector<std::pair<std::string, int> >::iterator i = items_.begin(); i != items_.end(); ++i) {
			std::cout << "[ '" << i->first << "' - " << i->second << " ] ";
			count++;
			if (count == nodesInLevel) {
				level++;
				nodesInLevel = pow(d_ary,level);
				std::cout << "\n";
				count = 0;
			}
		}
	}
	else { // basic vector print
		std::cout << "<----- Vector Visualized ---->\n";
		for (std::vector<std::pair<std::string, int> >::iterator i = items_.begin(); i != items_.end(); ++i) {
			std::cout << "[ '"<< i->first << " - " << i->second << " ] ";
			if (count == 8) {
				std::cout << "\n";
				count = 0;
			}
		}
	}
	std::cout << "\n<============================>\n\n";
}

void MinHeap::printChildrenOf(int index) {
	int parentIndex = index;
	std::cout << "\nParent...\n[ " << items_[index].first << " - " << items_[index].second << " ]\nChildren...\n";
	try {
		index = getFirstChildIndex(index);
		for (unsigned int i = index; ((i < d_ary+index) && (i <= items_.size()-1)); ++i) {
			std::cout << "[ " << items_[i].first << " - " << items_[i].second << " ] ";
		}
		// print smallest child of a parent
		std::cout << "\nSmallest Child...\n[ " << items_[getMinChild(parentIndex)].first << " - " << items_[getMinChild(parentIndex)].second << " ]\n";
	} catch (std::out_of_range){
		std::cerr << "\nNo Children\n";
	}
}