#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector <int> v(n), p(n);
  for(auto &i: v) cin >> i;
  map <int, int>  ind, mx;
  int mxi = 0, mxind;

  for (int i = 0; i < n; i++) {
    ind[v[i]] = i;
    mx[v[i]] = mx[v[i] - 1] + 1;
    if(ind.count(v[i] - 1)) p[i] = ind[v[i] - 1];
    else p[i] = i;
    if(mx[v[i]] > mxi) {
      mxi = mx[v[i]];
      mxind = i;
    }
  }

  cout << mxi << endl;
  vector <int> pp;
  int i = mxind;
  do {
    pp.push_back(i); 
    i = p[i];
  } while(i != p[i]);

  reverse(pp.begin(), pp.end());
  for(auto i: pp) cout << i + 1 << ' ';
  cout << endl;
}