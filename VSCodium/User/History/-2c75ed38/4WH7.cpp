#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  map <int, int> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    m[x]++;
  }
  vector <int> pp;
  for(auto i: m) pp.push_back(i.second);

  vector <vector <int>> dp(n, vector <int> (2*n + 1, -1));

  function <int(int, int)> f = [&](int i, int rem) {
    if(i == pp.size()) return 0;
    if(dp[i][rem] != -1) return dp[i][rem];
    int mx = f(i + 1, rem + 1);
    if(pp[i] < rem) 
      mx = max(mx, 1 + f(i + 1, rem - pp[i] - 1));
    return dp[i][rem] = mx;
  };

  cout << m.size() - f(0, 1) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}