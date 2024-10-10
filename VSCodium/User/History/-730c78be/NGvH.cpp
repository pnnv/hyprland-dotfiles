#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <vector <int>> v;
	for(int i = 1; i <= n; i++) {
		vector <int> tmp;
		for(int j = 0; j < i; j++) {
			int x; cin >> x;
			tmp.push_back(x);
		}
		v.push_back(tmp);
	}
	int c = 0;
	for(int i = 0; i < n; i++) {
		int a = min(i, c), b = max(i, c);
		c = v[b][a] - 1;
	}

	cout << c;
}