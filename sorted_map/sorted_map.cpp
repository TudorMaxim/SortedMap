#include "sorted_map.h"

sortedMap::sortedMap() : list(doublyLinkedList()) {}

sortedMap::~sortedMap() {}

bool sortedMap::realtion(const element& x, const element& y) {
	return x.getKey() < y.getKey();
}

void sortedMap::add(const std::string& key, const int& val) {
	node* found = list.findByKey(key);
	if (found != NULL)
		return;
	element to_add(key, val);
	node* it = this->list.head;
	while ( it != NULL && this->realtion(it->getInfo(), to_add)) {
		it = it->next;
	}
	if (it == NULL) {
		this->list.insertTail(to_add);
		return;
	}
	it = it->prev;
	if (it == NULL) {
		this->list.insertHead(to_add);
		return;
	}
	this->list.insertAfter(it, to_add);
}

void sortedMap::remove(const std::string& key) {
	node* found = list.findByKey(key);
	if (found == NULL)
		return;
	this->list.remove(found);
}

int sortedMap::search(const std::string& key) {
	node* found = list.findByKey(key);
	if (found == NULL)
		return 0;
	return found->getInfo().getVal();
}

int sortedMap::size() {
	return this->list.getSize();
}

void sortedMap::iterator(sortedMapIterator& iter) const {
	node* it = this->list.head;
	/*while (it != NULL) {
		iter.map.add(it->getInfo().getKey(), it->getInfo().getVal());
		it = it->next;
	}*/
	iter.map = *this;
	iter.current = this->list.head;
}

sortedMapIterator::sortedMapIterator() {}

sortedMapIterator::~sortedMapIterator() {}

element sortedMapIterator::getCurrent() {
	return this->current->getInfo();
}

bool sortedMapIterator::valid() {
	return this->current != NULL;
}

void sortedMapIterator::next() {
	this->current = this->current->next;
}

void sortedMapIterator::prev() {
	this->current = this->current->prev;
}

void sortedMapIterator::remove() {
	this->current = this->current->next;
	this->map.remove(current->prev->getInfo().getKey());
}