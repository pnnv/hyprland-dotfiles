#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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


class Solution {
public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    HashedString hs(s), ha(a), hb(b);
    oset <int> ia, ib;
    for(int i = 0; i <= s.size() - a.size(); i++)
      if(hs.get_hash(i, i + a.size() - 1) == ha.get_hash(0, a.size() - 1)) ia.insert(i);
    for(int i = 0; i <= s.size() - b.size(); i++)
      if(hs.get_hash(i, i + b.size() - 1) == hb.get_hash(0, b.size() - 1)) ib.insert(i);
    
    vector <int> ans;
    if(ib.empty()) return ans;
    for(auto i: ia) {
      int o = ib.order_of_key(i);
      int cl = *ib.find_by_order(o);
      if(abs(i - cl) <= k) {
        ans.push_back(i); continue;
      }
      if(o > 0) {
        cl = *ib.find_by_order(o - 1);
        if(abs(i - cl) <= k) ans.push_back(i);
      }
    }
    return ans;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}