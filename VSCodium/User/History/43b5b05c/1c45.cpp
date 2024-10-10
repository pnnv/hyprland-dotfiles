#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	set <ll> e, o;
	for(auto &i: v) {
		cin >> i;
		if(i & 1) o.insert(i);
		else e.insert(i);
	}	
	vector <int> op;
	int k = 0;
	while(1) {
		if(e.size() > 1) {
			ll a = *e.begin(); e.erase(a);
			ll b = *e.begin(); e.erase(b);
			o.insert(a + (b - a) / 2LL);
			op.push_back((b - a) / 2LL);
			k++;
		}
		if(k >= 40) break;
		if(o.size() > 1) {
			ll a = *o.begin(); o.erase(a);
			ll b = *o.begin(); o.erase(b);
			e.insert(a + (b - a) / 2LL);
			op.push_back((b - a) / 2LL);
			k++;
		}
		if(k >= 40) break;
		if(e.size() <= 1 && o.size() <= 1) break;
	}
	if(e.size() + o.size() <= 1 && k <= 40) {
		cout << op.size() << endl;
		for(auto i: op) cout  << i << ' ';
		cout << endl;
	} else cout << -1 << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}