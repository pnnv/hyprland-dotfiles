#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	auto q = [](int X, int Y) {
		cout  << "? " << X << ' ' << Y << endl;
		cout.flush();
		int x; cin >> x;
		return x;		 
	};

	int n; cin >> n;
	set <pair <int, int>> s;
	map <pair <int, int>, int> mq;
	
	function <void(int, int)> f = [&](int A, int B) {
		int a = A, b = B;
		if(a == b) return;
		if(a > b) swap(a, b);
		int x;
		if(mq.count({a, b})) x = mq[{a, b}];
		else x = q(a, b);
		mq[{a, b}] = x;

		if(x == a) {
			s.insert({a, b});
			return;
		} else{
			f(a, x); f(x, b);
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
	int t; cin >> t;
	while(t--) snu();
}