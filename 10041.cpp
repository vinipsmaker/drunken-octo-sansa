#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>

using namespace std;

inline int dist(const vector<int> &v, int a) {
	int sum = 0;
	for (vector<int>::const_iterator it = v.begin() ; it != v.end() ; ++it ) {
		sum += abs(a - *it);
	}
	return sum;
}

inline void work(vector<int> &v) {
	sort(v.begin(), v.end());
	int lowest = dist(v, v.front());
	for (int i = v.front() + 1; i < v.back(); i++) {
		int current = dist(v, i);
		if (lowest > current)
			lowest = current;
	}
	cout << lowest << '\n';
}

int main() {
	int c;
	vector<int> v;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n; // parents
		cin >> n;
		for (int j = 0; j < n; j++) {
			int elem;
			cin >> elem;
			v.push_back(elem);
		}
		work(v);
		v.clear();
	}
}
