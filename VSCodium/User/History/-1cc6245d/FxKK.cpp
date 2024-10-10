#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector <vector <int>> seq;
	vector <int> cur;

	int n, k; cin >> n >> k;
	vector <int> v(n);
	for(auto &i: v) cin >> i;

	function <void (int, int)> f = [&](int i, int s) {
		if(i == n) {
			if(s % k == 0) seq.push_back(cur);
			return;
		}
		for(int j = 1; j <= v[i]; j++) {
			cur.push_back(j);
			f(i + 1, s + j);
			cur.pop_back();
		}
	};

	f(0, 0);

	for(auto i: seq) {
		for(auto j: i) cout  << j << ' ';
		cout  << endl;
	}
}