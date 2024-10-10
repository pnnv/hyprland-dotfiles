#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m; cin >> n >> m;
  vector <string> g;
  string pp(m + 2, '.'); g.emplace_back(pp);
  for (int i = 0; i < n; i++) {
    string p = ".";
    string s; cin >> s; p += s; p.push_back('.');
    g.emplace_back(p);
  }
  g.emplace_back(pp);
  for(auto i: g) cout << i << endl;
  // vector <ll> row(m + 2), col(n + 2);
  // function <void(int, int)> fill = [&](int x, int y) {
    
  // }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}