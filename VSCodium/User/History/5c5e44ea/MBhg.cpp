#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  if((k & 1) && cout << "No\n") return;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // int t; cin >> t;
  // while(t--) snu();

  vector <int> v = {1, 2, 3, 4, 5, 6};
  int mx = 0;
  do {
    int pp = 0;
    for(int i = 0; i < 6; i++) {
      pp += abs(v[i] - (i + 1));
    }
    mx = max(mx, pp);
  } while(next_permutation(v.begin(), v.end()));

  cout << mx << endl;
}