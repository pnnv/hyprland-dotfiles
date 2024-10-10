#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  vector <int> x(n);
  int mx = 0, xx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, v[i]);
    if(mx == i + 1) { x[i] = 1;  xx++; }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if(x[i] == 0) {
      if(i == 0 || x[i - 1] == 1) {
        if(v[i + 1] == i + 1) {
          cnt++; i++;
        }
        mx = max(mx, cnt + xx);
      }
    } else {
      if(v[i - 1] == i + 1) {
        cnt++;
        mx = max(mx, cnt + xx); i++;
      } else cnt = 0;
    }
  }
  for(auto i: x) cout << i << ' '; cout << endl;
  cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}