#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class HashedString {
private:
  static const ll M = (1LL << 61) - 1;
  static const ll B;
  static vector<ll> pow;
  vector<ll> p_hash;
  __int128 mul(ll a, ll b) { return (__int128)a * b; }
  ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
public:
  HashedString(const string &s) : p_hash(s.size() + 1) {
	while (pow.size() < s.size()) 
	  pow.push_back(mod_mul(pow.back(), B));
	p_hash[0] = 0;
	for (int i = 0; i < s.size(); i++)
	  p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
	
  }
  ll get_hash(int start, int end) {
	ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
	return (raw_val + M) % M;
  }
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
int freq_target[26], freq_curr[26];


void snu() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	if(n > m) {
		swap(n, m); swap(s, t);
	}

	if(s == t && cout << 0 << endl) return;
	if(s.front() != t.front() && cout << -1 << endl) return;

	int rem = m - n;
	HashedString hs(s), ht(t);
	
	for(int i = 0; i < n; i++) {
		bool pref = false, suf = false;
		if(hs.get_hash(0, i) == ht.get_hash(0, i)) pref = true;
		if(i + rem + 1 >= m || hs.get_hash(i + 1, n - 1) == ht.get_hash(i + rem + 1, m - 1)) suf = true;
		if(pref && suf && cout << 1 << endl) return;
	}

	cout << 2 << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}