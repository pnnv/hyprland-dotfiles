#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  map <char, char> m;
  for(char i = 'a'; i <= 'z'; i++) m[i] = i;

  for(auto &i: s) {
    char c = m[i];
    int op = int(c - 'a');
    if(op <= k) {
      k -= op;
      for(char x = c; x >= 'a'; x--) m[x] = 'a';
    } else {
      for(char x = c; x >= 'a'; x--) m[x] = min(m[x], char(c - op));
      k -= op;
    }
    cout << c << ' ';
  }
  for(auto &i: s) i = m[i];
  cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}