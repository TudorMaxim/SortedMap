#include <crtdbg.h>
#include "tester.h"

using namespace std;

void testing() {
	tester t;
	t.testDLL();
	t.testSortedMap();
}

bool isNumber(string s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}
void readData(sortedMap& M) {
	ios_base::sync_with_stdio(false);
	ifstream fin("grades.txt");
	string line;
	int grade = 0;
	while (!fin.eof()) {
		getline(fin, line);
		if (isNumber(line)) {
			grade = stoi(line);
		}
		else {
			M.add(line, grade);
		}
	}
}

void printData(const sortedMap& M) {
	ios_base::sync_with_stdio(false);
	cout << "Catalog: \n";
	sortedMapIterator it;
	M.iterator(it);
	it.remove();
	while (it.valid() == true) {
		string result;
		if (it.getCurrent().getVal() >= 5)
			result = "passed";
		else 
			result = "failed";
		cout << it.getCurrent().getKey() << " " << it.getCurrent().getVal() << " " << result << "\n";
		it.next();
	}


	/*cout << "Prove delete: \n";
	sortedMapIterator it2;
	M.iterator(it2);
	while (it2.valid() == true) {
		string result;
		if (it2.getCurrent().getVal() >= 5)
			result = "passed";
		else
			result = "failed";
		cout << it2.getCurrent().getKey() << " " << it2.getCurrent().getVal() << " " << result << "\n";
		it2.next();
	}*/

}

void createCatalog() {
	sortedMap M;
	readData(M);
	printData(M);
}

int main() {
	testing();
	createCatalog();
	_CrtDumpMemoryLeaks();
    return 0;
}