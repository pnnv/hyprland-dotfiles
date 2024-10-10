#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	vector <int> v(4);
	for(auto &i: v) {
		cin >> i; 
	}
	{
		int a = max(v[0] - (n - 2), 0), b = max(v[2] - (n - 2), 0);
		if(a < b) swap(a, b);
		
	}
	swap(v[0], v[1]); swap(v[2], v[3]);

	cout << "YES\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}