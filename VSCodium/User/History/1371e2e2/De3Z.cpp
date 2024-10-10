#include <bits/stdc++.h>
#include <climits>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

  ll mn = LONG_LONG_MAX;
  int n; cin >> n;
  vector <ll> v(n);
  for (auto &i: v) cin >> i;

  for (int i = 0; i < n; i++)  {
    vector <ll> c(n);
    ll op = 0;
    for(int j = i - 1; j >= 0; j--) {
      ll pp = c[j + 1] / v[j];
      c[j] = v[j] * (pp + 1LL);
      op += (pp + 1);
    }
    for(int j = i + 1; j < n; j++) {
      ll pp = c[j - 1] / v[j];
      c[j] = v[j] * (pp + 1LL);
      op += (pp + 1);
    }
    mn = min(mn, op);
  }
  cout << mn << endl;
}