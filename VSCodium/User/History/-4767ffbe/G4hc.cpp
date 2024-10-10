#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  vector <int> v(n);
  map <int, int> m;
  for(auto &i: v) {
    cin >> i; m[i]++;
  }
  int cnt = 0, mx = -1, l = -1, r = -1;

  for(auto i: v) {
    if(m[i] >= k) {
      cnt++;
      if(cnt > mx) {
        mx = cnt;
        l = i - cnt + 1;
        r = i;
      }
    } else cnt = 0;
  }


  if(mx == -1 && cout << -1 << endl) return;
  cout << l + 1 << ' ' << r + 1 << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}