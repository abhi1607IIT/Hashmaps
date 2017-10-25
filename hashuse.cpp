#include <iostream>
#include "hashmap.h"
using namespace std;

int main() {
	hashmap<int> h;
	char a[] = "abc";
	char b[] = "abc";
	h.insert(a, 10);

	if (h.containsKey(b)) {
		cout << h.find(b) << endl;
	}
	cout << h.find(b) << endl;
	h.deleteKey(a);
	cout << h.find(b) << endl;

}

