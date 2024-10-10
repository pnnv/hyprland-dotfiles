#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	vector <int> v(6);
	iota(v.begin(), v.end(), 1);
	
	do {
		int s = 0;
		for(int i = 0; i < 6; i += 2) {
			s += (abs(v[i] - v[i + 1]));
		}
		if(s == 9) {
			for(auto i: v) cout << i << ' ';
			 cout << endl;
		}
	} while(next_permutation(v.begin(), v.end()));
}