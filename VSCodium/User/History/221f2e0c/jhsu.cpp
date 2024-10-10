#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	auto q = [](int a, int b) {
		cout  << "? " << a << ' ' << b << endl;
		cout.flush();
		int x; cin >> x;
		return x;		 
	};

	int n; cin >> n;
	set <pair <int, int>> s;
	map <pair <int, int>, int> mq;
	
	function <void(int, int)> f = [&](int a, int b) {
		if(a == b) return;
		if(a > b) swap(a, b);
		int x;
		if(mq.count({a, b})) x = mq[{a, b}];
		else x = q(a, b);
		mq[{a, b}] = x;

		if(x == a) {
			s.insert({min(a, b), max(a, b)});
			return;
		} else{
			f(min(a, x), max(a, x)); 
			f(min(x, b), max(x, b));
		}
	};

	for(int i = 1; i < n; i++)
		f(i, i + 1);
	
	cout << "! ";
	for(auto i: s) cout << i.first << ' ' << i.second << ' ';
	cout << endl;
	cout.flush();
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}