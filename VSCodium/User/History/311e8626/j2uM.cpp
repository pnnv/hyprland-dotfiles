#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setIO(string name) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int32_t main() {
  setIO("hps");
  
  int n, k; cin >> n >> k;
  vector <int> v(n);
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    if(c == 'H') v[i] = 0;
    else if(c == 'P') v[i] = 1;
    else if(c == 'S') v[i] = 2;
  }

  vector <vector <vector <int>>> dp(n, vector <vector <int>> (k + 1, vector <int> (3, -1)));

  // for (int i = 0; i < n; i++) {
  //   for
  // }

  function <int(int, int, int)> f = [&](int i, int kk, int c) {
    if(kk > k || i >= n) return 0;
    if(dp[i][kk][c] != -1) return dp[i][kk][c];
    int cur = f(i + 1, kk, c);

    if(c == v[i]) cur++;
    else cur = max(cur, 1 + f(i + 1, kk + 1, v[i]));

    return dp[i][kk][c] = cur;
  };

  cout << max({f(0, 0, 0), f(0, 0, 1), f(0, 0, 2)}) << endl;
}