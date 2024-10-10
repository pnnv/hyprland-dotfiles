#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n); map <int, int> m;
  for(auto &i: v) {
    cin >> i; m[--i]++;
  }
  if(n == 1 && cout << "1\n1\n1\n\n") return;
  vector <int> vis(n, false);
  vector <vector <int>> ps;  
  for (int i = 0; i < n; i++) {
    if(m[i] == 0) {
      int p = i;
      vector <int> path;
      while(v[p] != p && !vis[p]) {
        vis[p] = true;
        path.push_back(p + 1);
        p = v[p];
      }
      if(p == v[p] && !vis[p]) {
        vis[p] = true;
        path.push_back(p + 1);
      }
      reverse(path.begin(), path.end());
      ps.push_back(path);
    }
  }

  cout << ps.size() << endl;
  for(auto p: ps) {
    cout << p.size() << endl;
    for(auto i: p) cout << i << ' '; cout << endl;
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}