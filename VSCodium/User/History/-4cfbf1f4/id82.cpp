#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int a, b, k; cin >> a >> b >> k;
  map <int, int> ma, mb;
  vector <int> va(k), vb(k);
  for(auto &i: va) cin >> i;
  for(auto &i: vb) cin >> i;
  ma[va[0]]++; mb[vb[0]]++;
  ll ans = 0;
  for(int i = 1; i < k; i++) {
    ans += (i - ma[va[i]] - mb[vb[i]]);
    ma[va[i]]++; mb[vb[i]]++;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}