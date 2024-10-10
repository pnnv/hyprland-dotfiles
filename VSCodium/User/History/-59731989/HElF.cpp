#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <int> p(n + 1), e;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; 
    if(x <= n && p[x] == 0) p[x] = 1;
    else e.push_back(x);
  }
  sort(e.begin(), e.end(), greater<>());
  int ans = e.size();
  for(int i = 1; i <= n; i++)  {
    if(p[i] == 0) {
      if(e.back() > (2 * i)) e.pop_back();
      else {
        cout << -1 << endl; return;
      }
    }
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}