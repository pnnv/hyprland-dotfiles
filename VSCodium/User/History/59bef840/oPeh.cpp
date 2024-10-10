#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m, k; cin >> n >> m >> k;
  vector <vector <ll>> g(n, vector <ll> (m)); 
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      cin >> g[i][j];

  vector <vector <int>> pp(n + 1, vector <int> (m + 1));

  ll a = 0, b = 0;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    for(int j = 0; j < m; j++) {
      if(s[j] == '1') a += g[i][j], pp[i + 1][j + 1]++;
      else b += g[i][j];
    }
  }

  for(auto v: pp) {
    for(auto i: v) cout << i;
    cout << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}