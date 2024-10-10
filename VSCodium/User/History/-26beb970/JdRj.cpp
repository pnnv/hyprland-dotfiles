#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector <int> ans(n);
  if(k & 1) {
    for(int i = 0; i < n && k > 0; i++) {
      if(s[i] == '1') {
        s[i] = '0'; k--; ans[i] = 1;
      }
    }
    for(char &i: s) 
      i = (i == '1' ? '0' : '1');
  } else {
    for (int i = 0; i < n && k > 0; i++)
      if(s[i] == '0') { 
        s[i] = '1'; ans[i] = 1; k--;
      }
   
  }
  if(k > 0)
    s.back() = ((k&1) ? '0' : '1'), ans.back() += k;
  cout << s << endl;
  for(auto i: ans) cout << i << ' '; cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}