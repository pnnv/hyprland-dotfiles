#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef long long ll;

class Solution {
public:
  long long maximumTotalDamage(vector<int> &p) {
    sort(p.begin(), p.end());
    vector<long long> v(1, p.front());
    map<ll, ll> f;
    for (auto i : p) {
      f[i]++;
      if (i != v.back())
        v.push_back(i);
    }

    vector<long long> dp(v.size());
    dp[0] = f[v[0]] * v[0];

    for (int i = 1; i < dp.size(); i++) {
      if (i < 3) {
        if (v[i - 1] < v[i] - 2) {
          dp[i] = max(dp[i], f[v[i]] * v[i] + dp[i - 2]);
        }
        if (i == 2 && v[i - 2] < v[i] - 2) {
          dp[i] = max(dp[i], f[v[i]] * v[i] + dp[i - 2]);
        }
        dp[i] = max(dp[i - 1], f[v[i]] * v[i]);

      } else {
        if (v[i - 1] < (v[i] - 2))
          dp[i] = max(dp[i], (f[v[i]] * v[i]) + dp[i - 1]);
        if (v[i - 2] < (v[i] - 2))
          dp[i] = max(dp[i], (f[v[i]] * v[i]) + dp[i - 2]);
        dp[i] = max(dp[i - 1], (f[v[i]] * v[i]) + dp[i - 3]);
      }
    }
    ll mx = 0;
    for (auto i : dp)
      mx = max(mx, i);

    return mx;
  }
};

int32_t main() { return 0; }