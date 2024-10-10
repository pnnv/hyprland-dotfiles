#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector <string> p(k);
  for (int i = 0; i < n; i++)
    p[i % k].push_back(s[i]);
  int o = 0, z = 0, w = 0;
  
  for(int i = 0; i < k; i++) {
    char x = '?';
    for(auto j: p[i]) {
      if(j != '?') {
        if(x == '?') x = j;
        else {
          if(x != j && cout << "NO\n") return;
        }
      }
    }
    if(x == '?') w++;
    else if(x == '1') o++;
    else z++;
  }

  if(o < z) swap(o, z);
  if(w >= o - z) {
    w -= (o - z); z = o;
    o += w / 2;
    z += w / 2;
    if(w & 1) o++;
    cout << (o == z ? "YES\n" : "NO\n");
  } else {
    cout << "NO\n"; 
  }
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}