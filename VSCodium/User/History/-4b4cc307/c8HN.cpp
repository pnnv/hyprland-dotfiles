#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, k, x; cin >> n >> k >> x;
  vector <int> v;
  for (int i = 0; i < n; i++) {
    if(i == k) v.push_back(x);
    int p; cin >> p;
    v.push_back(p);
  }

  for(auto i: v) cout << i << ' '; cout << '\n';
}