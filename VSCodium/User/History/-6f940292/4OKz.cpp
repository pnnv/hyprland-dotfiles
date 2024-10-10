#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 3;
	vector <int> a(4);
	for(int i = 1; i < 4; i++) {
		a[i] += a[i & (i - 1)] + 1;
	}

	for(auto i: a) cout << i << ' ';
	cout  << endl;
}