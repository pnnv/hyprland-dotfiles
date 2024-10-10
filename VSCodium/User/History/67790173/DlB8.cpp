#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, a, b; cin >> n >> a >> b;
  swap(a, b);
  vector <vector <int>> g(n);
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  vector <int> len(n, -1);
  bool pp = true;
  int entr = -1;
  function <void(int, int)> dfs = [&](int p, int c) {
    if(pp && len[c] != -1) {
      entr = c; return;
    }
    for(auto i: g[c]) {
      if(i != p) {
        len[i] = len[c] + 1;
        dfs(c, i);
      }
    }
  };
  len[a - 1] = 0;
  dfs(-1, a  - 1);
  int x = len[entr];
  pp = false;
  len = vector <int> (n, -1);
  len[b - 1] = 0;
  dfs(-1, b - 1);
  
  cout << (len[entr] > x ? "Yes\n": "No\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}