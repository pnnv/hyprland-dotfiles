#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  int f = v.front(), l = v.back();

  int p = 0;
  int pre = 0;
  while(v[p] == f && p < n) {
    pre++; p++;
  }

  int suf = 0; p = n - 1;
  while(v[p] == l && p >= 0) {
    suf++; p--;
  }

  cout << min({n, f * (n - pre), l * (n - suf)}) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}