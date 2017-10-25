#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	v.push_back(40);
	v.push_back(40);
	v.push_back(60);
	v.push_back(70);
	v.erase(v.begin() + 2, v.begin() + 5);
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << endl;
		it++;
	}
}

