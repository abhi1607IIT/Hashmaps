#include <iostream>
using namespace std;

int64_t numBalB(int64_t h, int64_t* out) {
	if (h == 0) {
		return 1;
	}
	if (h == 1) {
		return 1;
	}
	if (out[h] > 0) {
		return out[h];
	}
	int64_t ans_1 = numBalB(h - 1, out);
	int64_t ans_2 = numBalB(h - 2, out);
	out[h] = ans_1*ans_1 + 2*ans_1*ans_2;
	return out[h];
}

int64_t numBalancedTrees(int64_t h) {
	if (h == 0) {
		return 1;
	}
	if (h == 1) {
		return 1;
	}
	int64_t ans_h_1 = numBalancedTrees(h - 1);
	int64_t ans_h_2 = numBalancedTrees(h - 2);
	return ans_h_1 * ans_h_1 + 2 * ans_h_1 * ans_h_2;
}



int main() {
	int64_t h;
	cin >> h;
	int64_t* out = new int64_t[h + 1];
	for (int64_t i = 0; i < h+ 1;i ++) {
		out[i] = 0;
	}
	cout << numBalB(h, out) << endl;
	cout << numBalancedTrees(h) << endl;
}

