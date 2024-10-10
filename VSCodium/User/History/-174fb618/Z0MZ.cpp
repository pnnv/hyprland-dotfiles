#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  vector <int> v(3);
  for(auto &i: v) cin >> i;
  sort(v.begin(), v.end());
  cout  << v.back() - v.front() << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}