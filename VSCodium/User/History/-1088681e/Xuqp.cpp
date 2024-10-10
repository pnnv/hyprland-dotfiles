#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	vector <int> c(n);
	auto inv = [&]() {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if(s[i] == '1') cnt++;
			else c[i] = cnt;
		}
		cnt = 0;
		for(int i = n - 1; i >= 0; i--) {
			if(s[i] == '0') cnt++;
			else c[i] = cnt;
		}
	};
	for (int i = 0; i < k; i++) {
		inv();
		int mx = 0, mxi = -1;
		for (int i = 0; i < n; i++) {
			if(c[i] >= mx) {
				mx = c[i]; mxi = i;
			}
		}
		if(mx == 0 && cout << 0 << endl) return;
		s[mxi] = (s[mxi] == '1' ? '0' : '1');
	}
	inv(); ll pp = 0;
	for (int i = 0; i < n; i++)
		if(s[i] == '1') pp += c[i];
	
	cout << pp << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}