#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int l, r; cin >> l >> r;
  int ans = 0; l--;
  
  for(int i = 0; i <= 18; i++) {
    int a = ((((1 << 20) - 1) >> (i + 1)) << i) & l;
    if(l & (1 << i)) a += (((1 << i) - 1) & l);
    int b = ((((1 << 20) - 1) >> (i + 1)) << i) & r;
    if(b & (1 << i)) b += (((1 << i) - 1) & r);
    ans = max(ans, b - a);
  }

  cout << (r - l - ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}