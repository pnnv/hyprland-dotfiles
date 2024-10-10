#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll ans = 0, nd = (1LL << 31) - 1, n, k; cin >> n >> k;
  vector <ll> ct(31);
  for (int _ = 0; _ < n; _++) {
    int i; cin >> i; nd &= i;
    for(int j = 30; j >= 0; j--) {
      if(i & (1LL << j)) ct[j]++;
    }
  }

  for(int i = 30; i >= 0; i--) {
    int op = n - ct[i];
    if(op >= k) {
      k -= op; ans |= (1LL << i);
    }
  }

  cout << (nd | ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}