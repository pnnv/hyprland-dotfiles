#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m; cin >> n >> m;
  vector <vector <int>> v(n + 2, vector <int> (m + 2));
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++)
      cin >> v[i][j];
  
  for(int j = 1; j <= m; j++) 
    for(int i = 1; i <= n; i++) 
      if(v[i][j] > v[i + 1][j] && v[i][j] > v[i - 1][j] && v[i][j] > v[i][j + 1] && v[i][j] > v[i][j - 1]) 
        v[i][j] = max({v[i + 1][j], v[i - 1][j], v[i][j + 1], v[i][j - 1]});
  

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cout << v[i][j] << ' ';
    }
    cout << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}