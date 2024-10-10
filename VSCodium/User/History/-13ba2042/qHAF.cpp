#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <ll, ll> f; f[0] = n;	
	multiset <ll> st;
	st.insert(n); st.insert(0);
	vector <ll> v(n);

	ll pp = (n * (n - 1LL)) >> 1LL;

	for(int _ = 0; _ < n; _++) {
		int a, b; cin >> a >> b; --a;

		pp -= (f[v[a]] * (f[v[a]] - 1LL) / 2LL);
		pp -= (f[b] * (f[b] - 1LL) / 2LL);

		st.erase(st.find(f[v[a]]));
		if(f.count(b)) st.erase(st.find(f[b]));
		f[b]++; f[v[a]]--;
		v[a] = b;
		
		pp += (f[v[a]] * (f[v[a]] - 1LL)) / 2LL;
		pp += (f[b] * (f[b] - 1LL) / 2LL);

		auto it = st.end();
		it = prev(it);
		ll mxf = *it;
		pp -= (f[0] * (f[0] + 1LL)) / 2LL;
		pp -= (mxf * (mxf + 1LL)) / 2LL;
		mxf += f[0];
		pp += (mxf * (mxf + 1LL)) / 2LL;

		cout << pp << ' ';
	}

	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}