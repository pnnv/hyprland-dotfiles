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
  vector <int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

  int n; cin >> n;
  vector <ll> c(71);
  for (int i = 0; i < n; i++) {
    int x; cin >> x; c[x]++;
  }

  for(auto &i: c) 
    if(i != 0) i = (1LL << (i - 1LL));

  vector <vector <mi>> dp(71, vector <mi> (1 << 19));
  dp[0][0] = 1;

  vector <ll> m(71);
  for(int i = 1; i < 71; i++) {
    ll mask = 0, pp = i;
    for(int j = 0; j < 19; j++) {
      while(pp % p[j] == 0) {
        pp /= p[j]; mask ^= (1 << j);
      }
    }
    m[i] = mask;
  }


  for(int i = 0; i < 70; i++) {
    for(int j = 0; j < (1 << 19); j++) {
      dp[i + 1][j ^ m[i + 1]] += dp[i][j] * c[i + 1];
      dp[i + 1][j] += dp[i][j] * (c[i + 1] == 0 ? 1LL : c[i + 1]);
    }
  }

  cout << int(dp[70][0]) - 1 << endl;
}