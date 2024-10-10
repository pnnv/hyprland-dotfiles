#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  map <int, int> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    m[x]++;
  }
  vector <pair <int, int>> f;
  for(auto i: m) f.push_back({i.first, i.second});
  sort(f.begin(), f.end(), [&](pair <int, int> a, pair <int, int> b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
  });

  ofr 

  int p = 1, q = 0, fre = 1;
  int ans = 0;
  while(p <= 5000 && q < f.size()) {
    while(m[p] == 0 && p <= 5000) p++;
    if(p == 5001) break;
    ans++; m[p] = 0;
    while(m[f[q].first] == 0) {
      q++;
      if(q == f.size()) break;
    }
    if(q != f.size()) m[f[q].first]--;
    p++;
  }
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}