#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <vector>

int hash(const char c);

class Iterator;

struct Node {
  char value;
  std::string dataValue;
  Node* next;
}; 

class HashTable { 

public:
  HashTable(int nbuckets);
  int count(const char& x);
  void insert(const char& x, const std::string& y);
  void erase(const char& x);
  Iterator begin() const;
  void clearHash();
  Iterator end() const;
  int size() const;
  const std::vector <Node*>& get_buckets() const;

private:
  std::vector <Node*> buckets;
  int hashSize;
  friend class Iterator;
};

class Iterator {

public:
  std::string get() const;
  void next();
  bool equals(const Iterator& other) const;

private:
  const HashTable* container;
  int bucket_index;
  Node* current;
  friend class HashTable;
};

void encodePrinter();
HashTable readTextFile(std::ifstream& file);
HashTable encode(std::ifstream& file, std::ifstream& file2, std::ifstream& file3);

#endif
