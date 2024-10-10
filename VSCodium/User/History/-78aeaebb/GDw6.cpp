#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  string s; cin >> s;
  if(n == 2 && cout << s << endl) return;

  if(n == 3) {
    int a = int(s[0] - '0'), b = int(s[1] - '0'), c = int(s[2] - '0');
    cout << min({(10*a + b) * c, (10*a + b) + c, a * (10*b + c), a + (10*b + c)}) << endl;
    return;
  }

  for(auto i: s) if(i == '0' && cout << 0 << endl) return;


  int sm = 0, ans = 696969;

  for(auto i: ) sm += int(i - '0');

  for(int i = 0; i < pp.size() - 1; i++) {
    int a = int(pp[i] - '0'), b = int(pp[i + 1] - '0');
    ans = min(ans, sm + (10 * a + b) - a - b);
  }

  cout << pp << ' ';

  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}