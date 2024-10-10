#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  string a, b; cin >> a >> b;
  if(a == b && cout << 0 << endl) return 0;

  map <string, int> dp; dp[b] = 0;
  ll mn = 1e10;

  function <ll (string, ll)> f = [&](string s, ll curs) {
    int p = 0;
    while(s[p] == b[p] && p < n) p++;
    if(p == n) {
      mn = min(mn, curs);
      return dp[s] = 0;
    }

    set <string> st;
    for(int i = p + 2; i < n - 1; i++) {
      if(s[i] == b[i]) {
        string tmp = s;
        swap(tmp[p], tmp[i]);
        swap(tmp[p + 1], tmp[i + 1]);
        
      }
    }
  };
}