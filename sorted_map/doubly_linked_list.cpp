#include "doubly_linked_list.h"

node::node() {}

node::node(const element& elem) : info(elem) {
	this->next = NULL;
	this->prev = NULL;
}

node::~node() {}

element& node::getInfo() {
	return this->info;
}

doublyLinkedList::doublyLinkedList() {
	this->head = NULL;
	this->tail = NULL;
	this->size = 0;
}

doublyLinkedList::~doublyLinkedList() {
	if (this->head == NULL) return;

	node* it = this->head;
	while (it != NULL) {
		it = it->next;
		if (it != NULL) 
			this->remove(it->prev);
	}
	this->remove(this->tail);
}


node* doublyLinkedList::find(const element& val) const {
	for (node* it = this->head; it != NULL; it = it->next) {
		if (it->info == val) {
			return it;
		}
	}
	return NULL;
}

node* doublyLinkedList::findByKey(const std::string& k) const {
	for (node* it = this->head; it != NULL; it = it->next) {
		if (it->info.key == k) {
			return it;
		}
	}
	return NULL;
}

void doublyLinkedList::insertTail(const element& val) {
	this->size++;
	node* newNode = new node;
	newNode->info = val;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (this->head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	} 
	else {
		newNode->prev = this->tail;
		this->tail->next = newNode;
		this->tail = newNode;
	}
}

void doublyLinkedList::insertHead(const element& val) {
	this->size++;
	node* newNode = new node;
	newNode->info = val;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (this->head == NULL) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;
	}
}

void doublyLinkedList::insertAfter(node* p, const element& val) {
	if (p == NULL) return;

	if (this->head == NULL || p == this->tail) {
		this->insertTail(val);
		return;
	}
	this->size++;
	node* n = p->next;
	node* newNode = new node;
	newNode->info = val;
	newNode->next = n;
	newNode->prev = p;
	p->next = newNode;
	n->prev = newNode;
}


void doublyLinkedList::remove(node* p) {
	if (p == NULL) return;
	if (this->head == NULL) return;

	this->size--;
	if (this->head == p && this->tail == this->head) {
		delete this->head;
		this->head = NULL;
		this->tail = NULL;
	}
	else if (this->head == p) {
		this->head = this->head->next;
		delete this->head->prev;
		this->head->prev = NULL;
	}
	else if (this->tail == p) {
		this->tail = this->tail->prev;
		delete this->tail->next;
		this->tail->next = NULL;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		p = NULL;
	}
}

void doublyLinkedList::iterator(doublyLinkedListIterator& it) {
	for (node* p = this->head; p != NULL; p = p->next) {
		it.dll.insertTail(p->getInfo());
	}
	it.current = it.dll.head;
}

doublyLinkedListIterator::doublyLinkedListIterator() {}

doublyLinkedListIterator::~doublyLinkedListIterator() {}

bool doublyLinkedListIterator::valid() {
	return this->current != NULL;
}

node* doublyLinkedListIterator::getCurrent() {
	return this->current;
}

void doublyLinkedListIterator::next() {
	this->current = this->current->next;
}

void doublyLinkedListIterator::prev() {
	this->current = this->current->prev;
}