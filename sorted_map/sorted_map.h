#include "doubly_linked_list.h"

class sortedMapIterator;

class sortedMap {
private:
	doublyLinkedList list;
	bool realtion(const element& x, const element& y);

public:
	sortedMap();
	~sortedMap();
	void add(const std::string& key, const int& val);
	void remove(const std::string& key);
	int search(const std::string& key);
	int size();
	void iterator(sortedMapIterator& it) const;

	friend class sortedMapIterator;
};


class sortedMapIterator {
private:
	sortedMap& map;
	node* current;

public:
	sortedMapIterator();
	~sortedMapIterator();
	element getCurrent();
	bool valid();
	void next();
	void prev();
	void remove();

	friend class doublyLinkedList;
	friend class sortedMap;
};
