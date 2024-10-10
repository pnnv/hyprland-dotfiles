#include <bits/stdc++.h>
#include <cstring>
using namespace std;

typedef long long ll;

void snu() {
  int l, r;
  cin >> l >> r;
  int ans = 0;
  l--;

  for (int i = 0; i <= 18; i++) {
    int a = (l >> (i + 1) << i);
    if (l & (1 << i))
      a += (((1 << i) - 1) & l) + 1;
    int b = (r >> (i + 1) << i);
    if (r & (1 << i))
      b += (((1 << i) - 1) & r) + 1;
    ans = max(ans, b - a);
  }

  cout << (r - l - ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  vector <int> pp = {99, 114, 121, 112, 116, 111, 123, 65, 83, 67, 73, 73, 95, 112, 114, 49, 110, 116, 52, 98, 108, 51, 125};
  string st;
  for(auto i: pp) st.push_back(char(i));
  cout << st;
  int t;
  cin >> t;
  while (t--)
    snu();
}