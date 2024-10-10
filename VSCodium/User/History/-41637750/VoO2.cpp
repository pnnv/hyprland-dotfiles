#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(4);
	for(auto &i: v) {
		cin >> i; 
	}
	for(int _ = 0; _ < 2; ++_) {
		int a = max(v[0] - (n - 2), 0), b = max(v[2] - (n - 2), 0);
		if(a < b) swap(a, b);
		if(a == b) {
			if(a == 1 && v[1] + v[3] < 2 && cout << "NO\n") return;
			else if(a == 2 && (v[1] < 2 || v[3] < 2) && cout << "NO\n") return;
		} else {
			if(a == 2 && (v[1] < 1 || v[3] < 1 || v[1] + v[3] < a + b) && cout << "NO\n") return;
			else if(a == 1 && v[1] == 0 && v[3] == 0 && cout << "NO\n") return;
		}
		swap(v[0], v[1]); swap(v[2], v[3]);
	}

	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}