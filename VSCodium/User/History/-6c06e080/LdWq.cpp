#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
  vector<int> nums;
  vector<vector<ll>> dp;
  ll f(int i, int p) {
    if (i == nums.size())
      return 0ll;
    if (dp[i][p] != -1)
      return dp[i][p];

    if (p == 0) {
      return dp[i][p] = f(i + 1, 1) + nums[i];
    } else {
      return dp[i][p] =
                 max(f(i + 1, 0) - ll(nums[i]), f(i + 1, 1) + ll(nums[i]));
    }
  };

public:
  long long maximumTotalCost(vector<int> &n) {
    nums = n;
    vector<vector<ll>> tmp(nums.size(), vector<ll>(2, -1));
    dp = tmp;
    return f(0, 0);
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    g[i].push_back(--x);
  }

  vector<int> ans(n, -1);
}