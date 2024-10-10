#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <string> g(2); cin >> g[0] >> g[1];
  // vector <vector <bool>> vis(2, vector <bool> (n, false));

  bool found = false;
  function <void (int, int)> fill = [&](int x, int y) {
    if(x == 1 && y == n) {
      found = true;
      return;
    }
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    if(g[x][y] == '1' || g[x][y] == '2') fill(x, y + 1);
    else {
      fill(x + 1, y); fill(x - 1, y);
    }
  }; fill(0, 0);
  cout  << (found ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}