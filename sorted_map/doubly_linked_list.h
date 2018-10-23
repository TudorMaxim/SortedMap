#pragma once
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>


class doublyLinkedListIterator;
class sortedMap;
class sortedMapIterator;

class element {
private:
	std::string key;
	int value;
public:
	element() {}
	element(const char* k, int v) : key(k), value(v) {}
	element(const std::string& k, int v) : key(k), value(v) {}
	element& operator = (const element& e) {
		this->key = e.key;
		this->value = e.value;
		return *this;
	}
	bool operator == (const element& other) {
		return this->key == other.key && this->value == other.value;
	}
	~element() {}

	std::string getKey() const {
		return this->key;
	}
	int getVal() const {
		return this->value;
	}
	friend class node;
	friend class doublyLinkedList;
	friend class doublyLinkedListIterator;
};

class node {
private:
	element info;
	node* prev;
	node* next;

public:
	node();
	node(const element& elem);
	~node();
	element& getInfo();
	friend class sortedMap;
	friend class sortedMapIterator;
	friend class doublyLinkedList;
	friend class doublyLinkedListIterator;
};


class doublyLinkedList {
private:
	node * head;
	node* tail;
	int size;
public:
	doublyLinkedList();
	~doublyLinkedList();

	int getSize() {
		return this->size;
	}
	node* find(const element& val) const;
	node* findByKey(const std::string& k) const;
	void insertTail(const element& val);
	void insertHead(const element& val);
	void insertAfter(node* p, const element& val);
	void remove(node* p);
	void iterator(doublyLinkedListIterator& it);

	friend class doublyLinkedListIterator;
	friend class sortedMap;
	
};

class doublyLinkedListIterator {
private:
	doublyLinkedList dll;
	node* current;

public:
	doublyLinkedListIterator();
	~doublyLinkedListIterator();
	node* getCurrent();
	bool valid();
	void next();
	void prev();
	friend class doublyLinkedList;
};