#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int _, n; cin >> _ >> n;
	vector <ll> v(n), b(n), a(n);
	for(auto &i: v) cin >> i;

	ll ca = (v[0] == 1 ? 1 : 0), cb = (v[0] == 2 ? 1 : 0);

	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1] + ca;
		b[i] += b[i - 1] + cb;
		if(v[i] == 1) ca++;
		if(v[i] == 2) cb++;
	}
	

	vector <ll> ra(n), rb(n);
	ca = (v[n - 1] == 1 ? 1 : 0), cb = (v[n - 1] == 2 ? 1 : 0);

	for(int i = n - 2; i >= 0; i--) {
		ra[i] += ra[i + 1] + ca;
		rb[i] += rb[i + 1] + cb;
		if(v[i] == 1) ca++;
		if(v[i] == 2) cb++;
	}

	for (int i = 0; i < n; i++) 
		cout << (abs((a[i] + ra[i]) - (b[i] + rb[i]))) << ' ';
	cout << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}