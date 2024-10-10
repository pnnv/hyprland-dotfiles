#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  int l, r; cin >> l >> r;
  int p = int(log2(r));
  int cnt = 0;
  for(int i = l; i <= r; i++) 
    if(!(i & (1 << p))) cnt++;
  
  cout << cnt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}