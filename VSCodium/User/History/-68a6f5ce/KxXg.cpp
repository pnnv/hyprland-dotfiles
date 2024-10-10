#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  int x = 0;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    if(s.size() > 4) x++;
  }

  cout << x << endl;
}