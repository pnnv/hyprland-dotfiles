#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, k; cin >> n >> k;
  k = n - k;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  sort(v.begin(), v.end());
  ll mn = LONG_LONG_MAX;
  for(int i = 0; i <= n - k; i++)
    mn = min(mn, v[i + k - 1] - v[i]);
  cout << mn << endl;
}