#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) cout << i + 1 << ' '; cout << endl;
  for(int i = ((n - 1) / 2); i <= n; i++) cout << i << ' ';
  for(int i = 1; i < n / 2; i++) cout << i << ' ';
  cout  << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}