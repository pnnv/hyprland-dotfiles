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
	string s; cin >> s;
	ll n = s.size();
	mi ans = 0;
	map <ll, ll> sm, sq;
	sm[0] = 0, sq[0] = 0;
	ll a = 0, b = 0;
	ll t = (n * (n + 1));
	
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '1') b++;
		else a++;
		ll cur = a - b;
		if(sm.find(cur) == sm.end()) {
			sm[cur] += i; sq[cur] += (i * i);
			continue;
		}
		ll a = i + 1;
		mi c = t;
		c -= ((2 * (a * a)) - (2 * a * (sm[cur])) + sq[cur] - sm[cur] + (2 * a));
		ans += c;
		sm[cur] += i; sq[cur] += (i * i);
	}
	ans = ans / 2;
	cout << int(ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}