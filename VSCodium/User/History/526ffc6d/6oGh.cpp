#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

struct mi {
  int v;
  explicit operator int() const { return v; }
  mi() { v = 0; }
  mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi &operator-=(mi &a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void snu() {
  ll l, r, k; cin >> l >> r >> k;
  if(k > 9 && cout << 2 << endl) return;
  ll pp = (k == 1 ? 10 : (k == 2 ? 5 : (k == 3 ? 4 : (k == 4 ? 3 : 2))));
  
  mi ans = pow(mi(pp), r - 1);
  if(l == 0 && cout << int(ans) << endl) return;
  ans -= pow(pp, l - 1);
  cout << int(ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}