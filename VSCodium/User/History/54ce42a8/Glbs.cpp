#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	if(k == 0 && cout  << 0 << endl) return;
	int cnt = 1;
	k -= n; 
	int pp = n - 1;
	while(n > 0) {
		n -= pp;
		if(n > 0) {
			n -= pp;
			cnt++;
		} else  {
			cout << cnt + 1 << endl; return;
		}
		pp--;
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}