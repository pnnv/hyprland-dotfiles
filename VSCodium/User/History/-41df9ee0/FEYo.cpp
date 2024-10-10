#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n);
  for (int i = 0; i < n; i++) v[i] = i + 1;
  for(auto i: v) cout << i << ' '; cout << '\n';
  for(int i = n / 2; i < n; i++) cout << v[i] << ' ';
  for(int i = 0; i < n / 2; i++) cout << v[i] << ' ';
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}