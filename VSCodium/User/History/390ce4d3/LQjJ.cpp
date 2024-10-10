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

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int h, w; cin >> h >> w;
  vector <vector <int>> g(h, vector <int> (w));
  vector <int> r(h), c(w);
  for(auto &i: r) cin >> i;
  for(auto &i: c) cin >> i;

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < r[i]; j++) g[i][j] = 1;
    if(r[i] < w) g[i][r[i]] = -1;
  }
  for(int i = 0; i < w; i++) {
    for(int j = 0; j < c[i]; j++) {
      if(g[j][i] == -1 && cout << 0 << endl) return 0;
      g[j][i] = 1;
    }
    if(c[i] < h) {
      if(g[c[i]][i] == 1 && cout << 0 << endl) return 0;
      g[c[i]][i] = -1;
    }
  }
  mi ans = 1;

  for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++)
      if(g[i][j] == 0) ans *= mi(2);

  cout << int(ans) << endl;
}