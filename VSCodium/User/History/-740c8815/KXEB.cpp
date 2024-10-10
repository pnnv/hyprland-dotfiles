#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	map <int, set <int>> st;

	for(int _ = 0; _ < n; _++) {
		int x; cin >> x;
		set <int> ne; ne.insert(x);
		for(int i = 0; i <= x; i++) 
			for(auto j: st[i]) 
				ne.insert(x ^ j);
		for(int i = x + 1; i <= 500; i++)
			for(auto j: ne) st[i].insert(j);
	}
	set <int> fin;

	for(int i = 0; i <= 500; i++)
		for(auto j: st[i]) fin.insert(j);

	cout << fin.size() << endl;
	for(auto i: fin) cout << i << ' ';
	cout << endl;
}