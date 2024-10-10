#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  char mx = 'a';
  for(auto &i: s) {
    if(i <= mx) {
      i = 'a'; continue;
    }
    int op = int(i - 'a');
    if(op <= k) {
      k -= op; i = 'a';
    } else {
      i -= op; k = 0;
    }
  }
  cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}