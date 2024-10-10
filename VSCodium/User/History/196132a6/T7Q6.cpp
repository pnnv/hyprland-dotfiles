#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector <string> g(n + 2);
  string pp(m + 2, '.');
  g[0] = pp; g[n + 1] = pp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    string t = "X"; t += s; t.push_back('X');
    g[i + 1] = t;
  }
  vector <int> p(m + 2);
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) 
      if(g[i][j] == '.' && g[i][j - 1] == 'X' && g[i - 1][j] == 'X') 
        p[j - 1] = 1;
        
  for(int i = 1; i < p.size(); i++) p[i] += p[i - 1];

  int q; cin >> q;
  for(; q--;) {
    int a, b; cin >> a >> b;
    cout << ((p[b] - p[a - 1]) == 0 ? "YES\n" : "NO\n");
  }
}