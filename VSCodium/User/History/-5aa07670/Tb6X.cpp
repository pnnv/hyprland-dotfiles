#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, a, b, c; cin >> a >> b >> c;
  string s; cin >> s;
  int w = 0;
  string ext, ans(n, 'x');
  for(int k = 0; k < n; k++) {
    char i = s[k];
    if(i == 'R') {
      if(b > 0) {
        b--; w++;
        ans[k] = 'P';
      }
    } else if(i == 'P') {
      if(c > 0) {
        c--; w++;
        ans[k] = 'S';
      } 
    } else {
      if(a > 0) {
        a--; w++;
        ans[k] = 'R';
      } 
    }
  }
  string  pp;
  for(int i = 0; i < a; i++) pp.push_back('R');
  for(int i = 0; i < b; i++) pp.push_back('P');
  for(int i = 0; i < c; i++) pp.push_back('S');

  for (int i = 0; i < n; i++) {
    if(ans[i] == 'x') {
      ans[i] = pp.back(); pp.pop_back();
    }
  }
  if(w >= ((n + 1) / 2)) {
    cout << "YES\n" << ans << endl;
  } else cout << "NO\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}