#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  string s; cin >> s;

  if(n == 2) {
    int a = int(s[0] - '0'), b = int(s[1] - '0');
    cout << ((10 * a) + b) << endl;
    return;
  }

  if(n == 3) {
    int a = int(s[0] - '0'), b = int(s[1] - '0'), c = int(s[2] - '0');
    cout << min({(10*a + b) * c, (10*a + b) + c, a * (10*b + c), a + (10*b + c)}) << endl;
    return;
  }
  for(auto i: s) if(i == '0' && cout << 0 << endl) return;

  int sm = 0, ans = 696969;
  for(auto i: s) if(i != '1') sm += int(i - '0');

  for(int i = 0; i < n - 1; i++) {
    int a = int(s[i] - '0'), b = int(s[i + 1] - '0');
    ans = min(ans, sm + (10*a + b) - (a == 1 ? 0 : a) - (b == 1 ? 0: b));
  }

  cout << int(ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}