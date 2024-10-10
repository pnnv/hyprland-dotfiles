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
		else {
			x = q(a, b);
			mq[{a, b}] = x;
		} 	

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
	for(auto i: s)
		cout << i.first << ' ' << i.second << ' ';
	cout << endl;
	cout.flush();
}

int32_t main() {
	int t; cin >> t;
	while(t--) snu();
}



/*

1
10
? 1 2
1
? 1 3
1
? 1 4
1
? 1 5
1
? 1 6
1
? 1 7
1
? 1 8
1
? 1 9
1
? 1 10
1
? 2 3
1
? 2 4
1
? 2 5
1
? 2 6
1
? 2 7
1
? 2 8
1
? 2 9
1
? 2 10
1
? 3 4
1
? 3 5
1
? 3 6
1
? 3 7
1
? 3 8
1
? 3 9
1
? 3 10
1
? 4 5
1
? 4 6
1
? 4 7
1
? 4 8
1
? 4 9
1
? 4 10
1
? 5 6
1
? 5 7
1
? 5 8
1
? 5 9
1
? 5 10
1
? 6 7
1
? 6 8
1
? 6 9
1
? 6 10
1
? 7 8
1
? 7 9
1
? 7 10
1
? 8 9
1
? 8 10
1
? 9 10
1
! 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 

*/