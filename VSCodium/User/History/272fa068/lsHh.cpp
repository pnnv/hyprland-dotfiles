#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int l, r, L, R; cin >> l >> r >> L >> R;
	if(l > L) {
		swap(l, L); swap(r, R);
	}
	int ans = 0;
	if(min(l, L) > max(l, L)) ans++;
	if(max(r, R) > min(r, R)) ans++;
	int i = max(0, min(r, R) - max(l, L) + 1);
	cout << i + ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}