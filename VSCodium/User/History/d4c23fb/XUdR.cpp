#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  int x = (n / 3) - 1, y = (n % 3) + 3;
  if(y == 3) {
    x++; y = 0;
  }
  vector <pair <int, int>> e; 
  for(int i = 0; i < x; i++) {
    e.push_back({3*i, 3*i + 1});
    e.push_back({3*i + 1, 3*i + 2});
    e.push_back({3*i, 3*i + 2});
  }
  if(y == 5) {
    for(int i = 1; i < 5; i++) e.push_back({3 * x + i, 3 * x + i + 1});
    e.push_back({3 * x + 1, 3 * x + 5});
  } else if(y == 4) {
    for(int i = 1; i < 4; i++) e.push_back({3 * x + i, 3 * x + i + 1});
    e.push_back({3 * x + 1, 3 * x + 4});
    e.push_back({3 * x + 1, 3 * x + 3});
  }

  cout << e.size() << endl;
  for(auto [a, b]: e) cout << a << ' ' << b << endl;
}