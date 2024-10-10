#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, r; cin >> n >> r;
  vector <int> v;
  set <int> st;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    st.insert(x);
  }
  for(auto i: st) v.push_back(i);
  n = v.size();
  int mn = n;
  for (int i = 0; i < n; i++) 
    mn = min(mn, max(n - i - 1, (v[i] + r - 1) / r));
  
  cout  << mn << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}