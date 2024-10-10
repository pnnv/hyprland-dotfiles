#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> a(n), b(n);
	for(auto &i: a) cin >> i;
	for(auto &i: b) cin >> i;
	
	for(int i = 0; i < n / 2; i++) {
		int j = n - i - 1;
		if(j - i > 1) {
			if((a[i] != b[i] || a[j] != b[j]) && cout << "Alice\n") return;
		}
	}
	cout << "Bob\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}