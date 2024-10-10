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
	string s; cin >> s;
	vector <int> l(26, -1);
	int mni = s.size(); char mnc;

	for(int i = 0; i < s.size(); i++) 
		l[int(s[i] - 'a')] = i;

	for(int i = 0; i < 26; i++) 
		if(l[i] < mni && l[i] != -1) 
			mni = l[i], mnc = char(s[i] + 'a');
		 

	string ns = "";
	for(auto i: s) if(i != mnc) ns.push_back(i);
	HashedString hs(ns);

	int len = 0;
	for(int i = 1; i <= ns.size() / 2; i++) 
		if(hs.get_hash(0, i - 1) == hs.get_hash(i, 2 * i - 1)) 
			len= i;
	if(len == 0 && cout << -1 << endl) return;

	string pp = ns.substr(0, len);
	string ini = "", rem = ""; rem.push_back(mnc);

	{
		int i = 0, j = 0;
		while(i < pp.size()) {
			if(s[i] == pp[j]) ini.push_back(s[i++]), j++;
			else ini.push_back(s[i++]);
		}
	}

	cout << ini << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}