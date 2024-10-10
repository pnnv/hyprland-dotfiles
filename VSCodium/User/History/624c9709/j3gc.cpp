#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

ll fac[MAXN + 1];
ll innv[MAXN + 1];

ll exp(ll x, ll n, ll m) {
	x %= m; ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m; n /= 2;
	} return res;
}
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}
void innverses() {
	innv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { innv[i - 1] = innv[i] * i % MOD; }
}
ll choose(int n, int r) { return fac[n] * innv[r] % MOD * innv[n - r] % MOD; }

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
  int n, k; cin >> n >> k;
  if(n & 1) {
    mi ans = pow(mi(2), k);
    mi pp = 0;
    for (int i = 2; i <= n - 1; i++) pp += choose(n, i);
    pp = pow(pp, k);
    ans += pp;
    cout << int(ans) << endl;
  } else {
    cout  << "PENIS\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  factorial(); innverses();
  int t; cin >> t;
  while(t--) snu();
}