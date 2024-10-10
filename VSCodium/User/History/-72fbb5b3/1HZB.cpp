#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector <int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

  int n; cin >> n;
  vector <ll> c(71);
  for (int i = 0; i < n; i++) {
    int x; cin >> x; c[x]++;
  }

  for(auto &i: c) 
    if(i != 0) i = (1LL << (i - 1LL));

  vector <vector <ll>> dp(71, vector <ll> (1 << 19));
  dp[0][0] = 1;

  vector <ll> m(71);
  for(int i = 1; i < 71; i++) {
    ll mask = 0, pp = i;
    for(int j = 0; j < 19; j++) {
      while(pp % p[j] == 0) {
        pp /= p[j]; mask ^= (1 << j);
      }
    }
    m[i] = mask;
  }

  // for(auto mask: m) cout << mask << ' ';

  for(int i = 0; i < 70; i++) {
    for(int j = 0; j < (1 << 19); j++) {
      dp[i + 1][j ^ m[i + 1]] += dp[i][j] * c[i + 1];
      dp[i + 1][j] += dp[i][j] * c[i + 1];
    }
  }

  // for(auto i: dp) {
  //   cout << i.front() << ' ';
  // }

  cout << dp[70][0] << endl;
}