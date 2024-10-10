#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	set <ll> e, o;
	for(auto &i: v) cin >> i;
	vector <int> op;
	
	for(int i = 0; i <= 40; i++) {
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
				ll a = *e.begin();
				if(a != 0) {
					op.push_back(a);
					for(auto &i: v) i = abs(i - a);
				}
				break;
			} else if(o.size() == 1) {
				ll a = *o.begin();
				op.push_back(a);
				for(auto &i: v) i = abs(i - a);
				break;
			}
		}
	}

	for(auto i: v)
		if(i != 0 && cout << -1 << endl) return;

	while(!op.empty() &&  op.back() == 0) op.pop_back();
	if(op.size() <= 40) {
		cout << op.size() << endl;
		for(auto i: op) cout << i << ' ';
		cout << endl; 
	} 
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}