#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int x; cin >> x;
	cout << (x ^ (1 << int(log2(x)))) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}