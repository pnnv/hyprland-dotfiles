#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  vector <vector <int>> t(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    t[--x].push_back(--y);
    t[y].push_back(x);
  }
  if(n & 1 && cout << -1 << endl) return 0;
  cout << "HICNC\n";
}