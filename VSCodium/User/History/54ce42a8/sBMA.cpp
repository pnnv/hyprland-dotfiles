#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	if(k == 0 && cout  << 0 << endl) return;
	int cnt = 1;
	k -= n; 
	int pp = n - 1;
	while(n > 0 && pp > 0) {
		n -= pp; pp--;
		cnt++;
	}
	if(n <= 0 && cout << cnt << endl) return;
	pp = n - 1;
	while(n > 0 && pp > 0) {
		n -= pp; pp--;
		cnt++;
	}
	cout << cnt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}