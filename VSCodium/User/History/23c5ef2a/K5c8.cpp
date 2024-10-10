#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	bool f = true, bk = true;
	for (int i = 0; i < n; i++) {
		if(a[i] != b[i])  {
			f = false;
			break;
		}
	}
	reverse(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		if(a[i] != b[i])  {
			bk = false;
			break;
		}
	}
	
	cout << ((f || bk) ? "Bob\n" : "Alice\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}