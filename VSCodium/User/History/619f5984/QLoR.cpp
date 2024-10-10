#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <ll> v(n);
  for(auto &i: v) cin >> i;
  vector <int> ind(n);
  for (int i = 0; i < n; i++) ind[i] = i;
  sort(ind.begin(), ind.end(), [&](int a, int b) { return v[a] < v[b]; });

  ll cs = v[ind[0]];
  vector <int> x(n);
  for (int i = 1; i < n; i++) {
    if(cs < v[ind[i]]) x[i]++;
    cs += v[ind[i]];
  }
  int pp = n;
  vector <int> ans(n);
  for(int i = n - 1; i >= 0; i--) {
    if(x[i] == 1) pp = i;
    ans[ind[i]] = pp;
  }

  for(auto i: ans) cout << i << ' '; cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}