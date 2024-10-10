#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n; if(n == 1 && cout << 1 << endl) return;
  for (int i = 0; i < n - 1; i++) cout << "1 "; cout << "0\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}