#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, m; cin >> n >> m;
  string a; cin >> a;
  set <int> s;

  for(int i = 0; i < m; i++) {
    int x; cin >> x;
    s.insert(x);
  }

  string c; cin >> c;
  sort(c.begin(), c.end());

  for(int i = 0; i < m - s.size(); i++) c.pop_back();

  int p = 0;
  for(auto i: s) a[i - 1] = c[p++];

  cout << a << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}