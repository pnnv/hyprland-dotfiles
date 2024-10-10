#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  sort(v.begin(), v.end(), greater<>());
  int ans = 0;

  for (int i = 0; i < k; i++) 
    if(v[2*i] == v[(2*i) + 1]) ans++;
  cout << ans << endl;
  for(int i = 2 * k; i < n; i++)
    ans += v[i];

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}