#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	set <ll> e, o;
	for(auto &i: v) cin >> i;
	vector <int> op;
	
	while(op.size() < 40) {
		e.clear(); o.clear();
		for(auto i: v) {
			if(i & 1) o.insert(i);
			else e.insert(i);
		}
		if(e.size() > 1) {
			int a = *e.begin(); e.erase(a);
			int b = *e.begin(); e.erase(b);
			for(auto &i: v) i = abs(i - (a + (b - a) / 2LL));
			op.push_back((a + (b - a) / 2LL));
		} else if(o.size() > 1) {
			int a = *o.begin(); o.erase(a);
			int b = *o.begin(); o.erase(b);
			for(auto &i: v) i = abs(i - (a + (b - a) / 2LL));
			op.push_back((a + (b - a) / 2LL));
		} else {
			if(e.size() == 1 && o.size() == 1) {
				cout << -1 << endl; return;
			} else if(e.size() == 1) {
				op.push_back(*e.begin());
				break;
			} else if(o.size() == 1) {
				op.push_back(*o.begin());
				break;
			}
		}
	}

	if(op.size() <= 40) {
		cout << op.size() << endl;
		for(auto i: op) cout << i << ' ';
		cout << endl; 
	} else cout << -1 << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}