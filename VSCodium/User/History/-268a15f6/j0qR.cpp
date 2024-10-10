#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	map <int, int> m;
	
	int q; cin >> q;
	for(; q-- ;) {
		int t; cin >> t;
		if(t == 1) {
			int x; cin >> x; m[x]++;
		} else if(t == 2) {
			int x; cin >> x; m[x]--;
			if(m[x] == 0) m.erase(x);
		} else {
			cout  << m.size() << endl;
		}
	} 
}