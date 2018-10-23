#include "tester.h"

tester::tester() {}

tester::~tester() {}

void tester::testDLL() {
	doublyLinkedList dll;
	doublyLinkedListIterator it, it2, it3;
	dll.insertHead(element("one", 1));
	dll.insertTail(element("two", 2));

	node* one = dll.find(element("one", 1));
	assert(one->getInfo() == element("one", 1));

	dll.insertAfter(one, element("three", 3));
	assert(dll.findByKey("three") != NULL);

	dll.iterator(it);
	assert(it.getCurrent()->getInfo() == element("one", 1));
	it.next();
	assert(it.getCurrent()->getInfo() == element("three", 3));
	it.next();
	assert(it.getCurrent()->getInfo() == element("two", 2));
	it.prev();
	assert(it.getCurrent()->getInfo() == element("three", 3));
	it.next();
	assert(it.valid() == true);
	it.next();
	assert(it.valid() == false);

	dll.remove(one);
	dll.iterator(it2);
	assert(it2.getCurrent()->getInfo() == element("three", 3));

}

void tester::testSortedMap() {
	sortedMap sm;
	sm.add(std::string("Tudor"), 10);
	sm.add(std::string("John"), 10);
	sm.add(std::string("Mark"), 10);
	assert(sm.size() == 3);

	assert(sm.search("Tudor") == 10);
	assert(sm.search("ALEX") == 0);

	sm.remove("John");
	assert(sm.size() == 2);

	sm.add("John", 10);

	sortedMapIterator it;
	sm.iterator(it);
	assert(it.valid() == true);
	assert(it.getCurrent() == element("John", 10));
	it.next();
	assert(it.getCurrent() == element("Mark", 10));
	it.next();
	assert(it.getCurrent() == element("Tudor", 10));
	it.prev();
	assert(it.getCurrent() == element("Mark", 10));
	it.next();
	it.next();
	assert(it.valid() == false);
}


