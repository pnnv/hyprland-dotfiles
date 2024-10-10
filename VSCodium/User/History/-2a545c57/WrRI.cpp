#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  if(x1 > y1) {
    if(y2 >= x1) cout << "NO\n";
    else cout << "YES\n";
  } else {
    if(x2 >= y1) cout << "NO\n";
    else cout << "YES\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}