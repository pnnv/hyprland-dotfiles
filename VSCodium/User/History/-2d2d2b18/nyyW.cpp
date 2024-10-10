#include <bits/stdc++.h>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[101][101][11][11];

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
  memset(dp, -1, sizeof(dp));

  function <ll (int, int, int, int)> f = [&](int x, int y, int p, int q) {
    if(dp[x][y][p][q] != -1) return dp[x][y][p][q];
    ll ans = 0;
    if(x == 0 && y == 0) {
      dp[x][y][p][q] = 1;
      return 1LL;
    }
    if(p < k1 && x > 0) ans += f(x - 1, y, p + 1, 0);
    if(q < k2 && y > 0) ans += f(x, y - 1, 0, q + 1);
    dp[x][y][p][q] = ans;
    return ans;
  };

  cout << f(n1, n2, 0, 0) << endl;
}