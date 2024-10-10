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
  int n; cin >> n;
  vector <int> a(n), b(n), c(n);
  set <int> f;
  for(auto &i: a) cin >> i;
  for(auto &i: b) cin >> i;
  for(auto &i: c) {
    cin >> i; f.insert(i);
  }

  int cnt = 0;
  vector <int> ch(n + 1);
  for (int i = 0; i < n; i++) {
    ch[a[i]] = b[i]; if(a[i] == b[i]) f.insert(a[i]);
  }
  vector <bool> vis(n + 1, false);
  for (int i = 1; i < n; i++) {
    if(!vis[i]) {
      bool pp = true;
      int cur = i;
      while(!vis[cur]) {
        if(f.count(cur)) pp = false;
        vis[cur] = true;
        cur = ch[cur];
      }
      if(pp) cnt++;
    }
  }
  cout << int(pow(mi(2), cnt)) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}