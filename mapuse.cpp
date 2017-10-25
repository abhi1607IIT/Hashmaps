#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

void printIntersectioniDu(int * a, int *b, int sizea, int sizeb) {
	unordered_map<int, int> map;
	for (int i = 0; i < sizea; i++) {
		map[a[i]] = map[a[i]] + 1;
	}

	for (int j = 0; j < sizeb; j++) {
		if (map[b[j]] > 0) {
			cout << b[j] << endl;
			map[b[j]]--;
		}
	}
}

void printIntersection(int * a, int *b, int sizea, int sizeb) {
	unordered_map<int, bool> map;
	for (int i = 0; i < sizea; i++) {
		map[a[i]] = true;
	}
	for (int i = 0; i < sizeb; i++) {
		if (map.count(b[i]) > 0) {
			cout << b[i] << endl;
		}
	}
}
/*
void verticalOrderHelper(BinaryTreeNode<int>* root, int level, 
		unordered_map<int, vector<int>*>& map, int& minV, int& maxV) {
	if (root == NULL) {
		minV = INT_MAX;
		maxV = INT_MIN;
		return;
	}
	vector<int>* v = map[level];
	if (v == NULL) {
		 map[level] = new vector<int>();
	}
	v->push_back(root->data);
	int lMin, rMin, lMax, rMax;
	verticalOrderHelper(root->left, level - 1, map, lMin, lMax);
	verticalOrderHelper(root->right, level + 1, map, rMin, rMax);
	minV = min(level, min(lMin, rMin));
	maxV = max(level, max(lMax, rMax));
}

void verticalOrder(BinaryTreeNode<int>* root) {
	unordered_map<int, vector<int>*> map;
	int minV = INT_MAX;
	int maxV = INT_MIN;
	verticalOrderHelper(root, 0, map, minV, maxV);
	for (int i = minV; i <= maxV; i++) {
		vector<int>* v = map[i];
		for (int j = 0; j < v->size(); j++) {
			cout << v->at(j) << " ";
		}
		cout << endl;
	}
}
*/
int main() {
	int arr1[] = {5,10,15,2,3,4,5,6,7,12,10};
	int arr2[] = {10,10,10,5, 1, 2};
	printIntersectioniDu(arr1, arr2, 11, 6);
	unordered_map<char*, int>	uomap;
	char a[] = "this";
	char b[] = "blah";
	uomap[a] = 1002;
	uomap[b] = 2332;

	unordered_map<char*, int>::iterator it = uomap.begin();
	while (it != uomap.end()) {
		cout << it->first << " " << it->second << endl;
		it++;
	}
	char c[] = "this";
	cout << uomap[b] << endl;
	//cout << uomap.at("sbue") << endl;
	cout << uomap.size() << endl;
	if (uomap.count("fygyt") > 0) {
		cout << uomap["fygyt"] << endl;
	}
	cout << uomap["fffsnsfygyt"] << endl;


	it = uomap.begin();
	while (it != uomap.end()) {
		cout << it->first << " " << it->second << endl;
		it++;
	}
	cout << uomap.size() << endl;
}

