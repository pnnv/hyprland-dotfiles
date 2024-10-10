#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <ll> w(n);
  map <int, int> deg;
  ll s = 0; 
  for(auto &i: w) {
    cin >> i; s += i;
  }

  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b; --a; --b;
    deg[a]++; deg[b]++;
  }

  vector <pair <ll, ll>> pp;
  for(auto i: deg)
    if(i.second != 1)
      pp.push_back({w[i.first], i.second - 1});
  
  sort(pp.begin(), pp.end());

  cout << s << ' ';
  for(int i = 2; i < n; i++) {
    if(pp.back().second == 0) pp.pop_back();
    s += pp.back().first; pp.back().second--;
    cout << s << ' ';
  }
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}