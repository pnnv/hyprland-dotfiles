#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  string a, b; cin >> a >> b;
  int p1 = 0, p2 = 0, n = a.size() + b.size();
  int ans = n;
  for(int i = 0; i < b.size(); i++) {
    int p = i, mn = n;
    for(int j = 0; j < a.size(); j++) {
      if(a[j] == b[p]) {
        p++; mn--;
        if(p == b.size()) break;
      }
    }
    ans = min(ans, mn);
  }

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}