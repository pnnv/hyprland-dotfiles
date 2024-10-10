#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> a, b;
	for (int i = 1; i <= n; i++) {
		if(i & 1) a.push_back(i);
		else b.push_back(i);
	}
	if(n == 1 && cout << 1 << endl) return;
	
	for(int i = 0; i < b.size(); i++) {
		cout  << a[i] << ' ' << b[i] << ' ';
	}
	if(n & 1) cout << a.back();
	cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}