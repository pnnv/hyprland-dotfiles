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
  int n = s.size();
  if((n & 1) && cout  << 0 << endl) return;
  int ans = 0;
  HashedString h(s);
  if(h.get_hash(0, (n >> 1) - 1) == h.get_hash((n >> 1), n - 1))
    ans += 2;

  for(int i = 0; i < n; i++) {
    int a = i + 1;
    int b = (n - (2 * a)) / 2;
    if(h.get_hash(0, a - 1) == h.get_hash(a, a + a - 1) 
      && h.get_hash(2 * a, 2*a + b - 1) == h.get_hash(2 * a + b, 2 * a + b + b - 1))
        ans++;
    if(2 * a >= n - 2) break;
  }

  cout  << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}