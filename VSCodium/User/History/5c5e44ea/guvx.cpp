#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n, k; cin >> n >> k;
  if((k & 1) && cout << "No\n") return;
  vector <int> p(n);
  for (int i = 0; i < n; i++)
    p[i] = i + 1;

  ll l = 0, r = n - 1;
  while(l < r && k > 0) {
    if(2ll * (r - l) <= k) {
      k -= 2ll * (r - l);
      swap(p[l], p[r]);
      l++; r--;
    } else {
      swap(p[l], p[l + (k / 2)]);
      k = 0; break;
    }
  }

  if(k != 0 && cout << "No\n") return;
  cout << "Yes\n";
  for(auto i: p) cout << i << ' ';
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}