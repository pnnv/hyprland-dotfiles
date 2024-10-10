#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <ll, ll> f; f[0] = n;	

	multiset <ll> st;

	vector <ll> v(n);

	ll pp = (n * (n - 1LL)) / 2LL;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; --a;



		if(v[a] != 0) pp -= (f[v[a]] * (f[v[a]] - 1LL) / 2LL);
		if(b != 0) pp -= (f[b] * (f[b] - 1LL) / 2LL);

		 if(v[a] != 0) if(st.count(f[v[a]]))  st.erase(st.find(f[v[a]]));
		if(b != 0) if(st.count(f[b])) st.erase(st.find(f[b]));

		f[b]++; f[v[a]]--;
		if(v[a] != 0) st.insert(f[v[a]]);
		if(b != 0) st.insert(f[b]);
		
		if(v[a] != 0) pp += (f[v[a]] * (f[v[a]] - 1LL)) / 2LL;
		if(b != 0) pp += (f[b] * (f[b] - 1LL) / 2LL);

		v[a] = b;

		auto it = st.rbegin();
		ll mxf = *it;

		pp -= (mxf * (mxf - 1LL)) / 2LL;
		mxf += f[0];
		pp += (mxf * (mxf - 1LL)) / 2LL;

		cout << pp << ' ';
	}

	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}