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
        ans[k] = '';
      } 
    } else {
      if(a > 0) {
        a--; w++;
        ans[k] = 'P';
      } 
    }
  }
  
  cout << ((w >= ((n + 1) / 2)) ? "yes")
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}