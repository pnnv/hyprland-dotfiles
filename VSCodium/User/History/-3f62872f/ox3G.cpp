#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <string> g(2); cin >> g[0] >> g[1];

  bool found = false;
  function <void (int, int, bool)> fill = [&](int x, int y, bool v) {
    if(x == 1 && y == n) {
      found = true;
      return;
    }
    if(x < 0 || x >= 2 || y < 0 || y >= n) return;
    if(g[x][y] == '1' || g[x][y] == '2') {
      if(!v) fill(x, y + 1, false);
    } else {
      if(v) fill(x, y + 1, false);
      else fill(x + 1, y, true); fill(x - 1, y, true);
    }
  }; fill(0, 0, false);
  cout  << (found ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}