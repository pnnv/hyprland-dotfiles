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
      if(s[j] == '1') {a += g[i][j]; pp[i + 1][j + 1]++;}
      else b += g[i][j];
    }
  }

  if(a == b && cout << "YES\n") return;
  ll dif = abs(a - b);
  bool chinchin = (a > b);

  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++)
      pp[i][j] += (pp[i - 1][j] + pp[i][j - 1] - pp[i - 1][j - 1]);

  vector <ll> x;
  
  for(int i = k; i <= n; i++) {
    for(int j = k; j <= m; j++) {
      int snow = pp[i][j] - pp[i - k][j] - pp[i][j - k] + pp[i - k][j - k];
      int xsnow = (k * k) - snow;
      x.push_back(abs(snow - xsnow));
    }
  }

  if(x.empty() && cout << "NO\n") return;
  int hc = x.front();
  for(int i = 1; i < x.size(); i++) hc = gcd<int32_t> (hc, x[i]);

  cout << (dif % hc == 0 ? "YES\n" : "NO\n");
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}