#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  int s = 0;
  for (int i = 0; i < n - 1; i++) {
    int x; cin >> x; s = max(s, x);
  }
  int x; cin >> x;
  s += x;
  cout << s << endl;

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}