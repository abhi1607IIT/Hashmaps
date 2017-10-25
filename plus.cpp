#include <iostream>
using namespace std;

int main() {
	int i = 10;
	int j = 20;
	cout << i << endl;
	cout << j << endl;
	int * p = new int;
	delete p;
	delete p;
}

