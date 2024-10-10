#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  n *= 2;
  int c = 0;
  vector <int> v(n);
  for(auto &i: v) cin >> i;
  for (int i = 0; i < n - 2; i++) {
    if(v[i] == v[i + 2]) c++;
  }
  cout << c << endl;
}