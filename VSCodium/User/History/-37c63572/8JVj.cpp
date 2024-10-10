#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector <ll> v(n);
	for(auto &i: v) cin >> i;
	map <pair <int, ll>, int> mp;
	
	function <int (int, ll)> nimber = [&](int rem, ll op) {
		if(mp.count({rem, op})) return mp[{rem, op}];
		set <int> st;
		for(ll i = 1; i <= rem; i++) 
			if((op >> i) & 1LL) 
				st.insert(nimber(rem - i, op ^ (1LL << i)));
		int mex = 0;
		for(ll i = 0; i <= st.size(); i++) {
			if(!st.count(i)) {
				mex = i;
				break;
			}
		}
		return mp[{rem, op}] =  mex;
	};

	ll pp = 0;
	for(auto i: v)
		pp ^= nimber(i, (1L << (i + 1)) - 1);
	cout << (pp == 0 ? "YES\n" : "NO\n") << endl;
}