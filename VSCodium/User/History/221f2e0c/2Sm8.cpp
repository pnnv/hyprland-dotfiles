#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	auto q = [&](int a, int b) {
		cout  << "? " << a << ' ' << b << endl;
		cout.flush();
		int x; cin >> x;
		return x;		 
	};

	int n; cin >> n;
	vector <int> vis(n, false);
	set <pair <int, int>> s;

	map <pair <int, int>, int> mq;
	
	function <void(int, int)> f = [&](int a, int b) {
		int x;
		if(mq.count({a, b})) x = mq[{a, b}];
		else x = q(a, b);
		
		if(x == a) {
			if(a > b) swap(a, b);
			s.insert({a, b});
			return;
		} else{
			f(a, x); f(x, b);
		}
	};

	for(int jmp = 2; jmp <= (n << 1); jmp <<= 1) 
		for(int i = 1; i + (jmp >> 1) <= n; i += jmp)  
			f(i, i + (jmp >> 1));
	
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