#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Hashtable.h"
#include "Filename.h"

// Compressing Hash Code
int hash(const char c) {
  int h = 0;
  h = c % 32;
  return h;
}


HashTable::HashTable(int nbuckets) {
  
  for (int i = 0; i < nbuckets; i++) {
    buckets.push_back(nullptr);
  }
  hashSize = 0;
}


int HashTable::count(const char& x) {
  
  int h = hash(x); 
  h = h % buckets.size();
  if (h < 0) { h = -h; }


  Node* current = buckets[h];
  while (current != nullptr) {
    
    if (current-> value == x) { 
      return 1; }
    
    current = current -> next; 
  }
  return 0;
}


void HashTable::insert(const char& x, const std::string& y) {
  
  int h = hash(x);
  h = h % buckets.size();

  
  if (h < 0) { 
    h = -h; }

  Node* current = buckets[h];

  
  while (current != nullptr) {
    if (current -> dataValue == y) { 
      return; }
    current = current -> next; }


  Node* new_node = new Node;
  new_node -> value = x;
  new_node -> dataValue = y;
  new_node -> next = buckets[h];
  buckets[h] = new_node;
  hashSize++;
}


void HashTable::erase(const char& x) {
  int h = hash(x);
  h = h % buckets.size();;
  if (h < 0) { h = -h; }

  Node* current = buckets[h];
  Node* previous = nullptr;

  
  while (current != nullptr) {
    if (current -> value == x) {
      
     
      if (previous == nullptr) {
        buckets[h] = current -> next; } 
        
      else {
        previous-> next = current -> next; }
        delete current;
        hashSize--;
        return;
      }
      previous = current;
      current = current->next;
  }
}

const std::vector<Node*>& HashTable::get_buckets() const {
  return buckets;
}

int HashTable::size() const {
  return hashSize;
}

Iterator HashTable::begin() const {
  Iterator iter;
  iter.current = nullptr;
  iter.bucket_index = -1;
  iter.container = this;
  iter.next();
  return iter;
}

Iterator HashTable::end() const {
  Iterator iter;
  iter.current = nullptr;
  iter.bucket_index = buckets.size();
  iter.container = this;
  return iter;
}

std::string Iterator::get() const {
  return current-> dataValue;
}

bool Iterator::equals(const Iterator& other) const {
  return current == other.current;
}

void Iterator::next() {
  
  if (bucket_index >= 0 && current->next != nullptr) {
    current = current->next; 
  }
  else {
    do {
      bucket_index++; } 
      
    while (bucket_index < container->buckets.size() && container->buckets[bucket_index] == nullptr); {
    
      if (bucket_index < container->buckets.size()) {
        current = container->buckets[bucket_index];
    }
    else { 
        current = nullptr;
      }
    }
  }
}

void HashTable::clearHash() {
    for (Node*& bucket : buckets) {
        Node* current = bucket;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        bucket = nullptr;
    }
    hashSize = 0;
}


HashTable readTextFile(std::ifstream& file) {
  
  const int BUCKETS = 101;
  char value;
  std::string dataValue;
  HashTable result(BUCKETS);

  while (file >> value >> dataValue) {
    result.insert(value, dataValue);
  }
  return result;
}


HashTable encode(std::ifstream& file, std::ifstream& file2, std::ifstream& file3) {

  HashTable cypherfile = readTextFile(file);

  std::string line; 
  
  while (std::getline(file2, line)) {
    
    std::istringstream iss(line);

    char letter;
    while (iss >> letter) { 

      int h = hash(letter);
      h = h % cypherfile.get_buckets().size();
      if (h < 0) { h = -h; }

      
      Node* current = cypherfile.get_buckets()[h];
      while (current != nullptr) {
        if (current-> value == letter) {
          std::cout << current-> dataValue << " ";
          break;
        }
        current = current -> next;
        }
      }
    std::cout << std::endl;
    HashTable hashTable = encode (file, file2, file3);
    hashTable.clearHash();
  }
  return cypherfile; 
}
