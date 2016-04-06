#include "../lib/hash_table.h"

long long HashTable::hash (const std::string &key) const {
  long long index = 0;
  int count = 1;
  int keyLength = key.length();

  for (std::string::const_iterator i = key.begin(); i != key.end(); ++i) {
    index = index + (pow (29, keyLength-count) * enumerateChar(*i));
    count++;
  }
  index = index % numberOfIndices;

  return index;
}

HashTable::HashTable () {
  data = new std::list<std::pair<std::string, int> > [31];
  numberOfIndices = 31;
  numberOfElements = 0;
}


HashTable::HashTable (int numIndices) {
  data = new std::list<std::pair<std::string, int>> [numIndices];
}


HashTable::~HashTable () {
  delete [] data;
}


void HashTable::add (std::pair<std::string, int> new_item) {
  if (isMaxLoad()) {
    resize();
  }

  data[ hash(new_item.first) ].push_back(new_item);

  numberOfElements++;
}


const int& HashTable::find(std::string key) const {
  int curIndex = hash(key);

  if (data[curIndex].empty()) throw std::out_of_range("Cannot find, hash table empty");

  for (std::list<std::pair<std::string, int> >::const_iterator it = data[curIndex].begin(); it != data[curIndex].end(); ++it) {
    if (it->first == key) return it->second;
  }

  throw std::out_of_range("Value not in hash table");
}


void HashTable::remove (std::string key) {
  int curIndex = hash(key);

  if (data[curIndex].empty())
    throw std::out_of_range("Cannot remove, hash table empty");

  std::list<std::pair<std::string, int> >::iterator itemToDel = data[curIndex].end();

  for (std::list<std::pair<std::string, int> >::iterator it = data[curIndex].begin(); it != data[curIndex].end(); ++it) {
    if (it->first == key) {
      itemToDel = it;
      break;
    }
  }

  if (itemToDel != data[curIndex].end()){
    data[curIndex].erase(itemToDel);
    numberOfElements--;

  }
  else {
    throw std::out_of_range("Cannot remove, not in hash table");
  }
}


void HashTable::print () {
  std::cout << "<=================>\n";
  std::cout << "Hash Table Contents\n";
  std::cout << "<=================>\n";
  for (int i = 0; i < numberOfIndices; i++) {
    if (!data[i].empty())
      std::cout << "\ntable[" << i << "]\n";
    for (std::list<std::pair<std::string, int> >::iterator it = data[i].begin(); it != data[i].end(); ++it) {
      std::cout << it->second << ", ";
    }
  }
  std::cout << std::endl;
}


void HashTable::update (std::pair<std::string, int> new_value) {
  remove (new_value.first);
  add (new_value);
}


bool HashTable::isMaxLoad () {
  if ( ( numberOfElements / numberOfIndices ) == 1 ) return true;
  return false;
}


void HashTable::resize () {
  int oldNumIndices = numberOfIndices;
  numberOfIndices = 2 * numberOfIndices + 1;
  std::list<std::pair<std::string, int> >* temp = new std::list<std::pair<std::string, int> > [numberOfIndices];

  for (int i = 0; i < oldNumIndices; i++) {
      for (std::list<std::pair<std::string, int> >::iterator it = data[i].begin(); it != data[i].end(); ++it) {
        temp[ hash( it->first ) ].push_back(make_pair(it->first, it->second));
      }
  }

  delete [] data;
  data = temp;
}

int HashTable::enumerateChar (char c) const {
  if (isdigit(c)) return c - '0';
  if (isalpha(c)) return tolower(c) - 'a';
  return -1;
}

int const & HashTable::operator[](std::string str) {
    return find(str);
}