#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll a, b, c; cin >> a >> b >> c;
	ll mx = (a * b * c);

	for(int i = 0; i <= 5; i++) 
		for(int j = 0; j+i <= 5; j++) 
			mx = max(mx, (a + i) * (b + j) * (c + (5 - (i + j))));

	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}