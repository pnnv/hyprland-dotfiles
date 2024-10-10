#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  string a, b; cin >> a >> b;
  int p1 = 0, p2 = 0, ans = a.size() + b.size();
  while(p1 < a.size() && p2 < b.size()) {
    if(a[p1] != b[p2]) p1++;
    else {
      ans--; p1++; p2++;
    }
  }

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}