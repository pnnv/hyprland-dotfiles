#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  map <int, int> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; m[x]++;
  }
  int cnt = 0, last = 0, l = 0, r = 0, mx = -1;
  for(auto &[a, b]: m) {
    if(b >= k) {
      if(last == a - 1) {
        cnt++;
        if(cnt > mx) {
          mx = cnt; l = a - cnt + 1; r = a;
        }
      } else {
        cnt = 1;
        if(cnt > mx) {
          mx = cnt; l = a - cnt + 1; r = a;
        }
      }
    } else cnt = 0;
  }

  if(mx == -1 && cout << mx << endl) return;
  cout << l << ' ' << r << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}