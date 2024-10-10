#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;

void snu() {
  int n; cin >> n;
  map <int, int> m;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    m[x]++;
  }
  int pp = n;
  for(auto [a, b]: m) 
    pp = min(pp, (n - b) * a);

  cout  << pp << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}