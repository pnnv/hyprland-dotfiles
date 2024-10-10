#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  if(k >= 27 && cout << string(n, 'a') << endl) return;
  map <char, char> m;
  for(char i = 'a'; i <= 'z'; i++) m[i] = i;
  int p = 0;
  while(int(s[p] - 'a') <= k && p < n) p++;
  if(p == n && cout << string(n, 'a') << endl) return;

  char mx = 'a';
  for(int i = 0; i < p; i++) {
    mx = max(mx, s[i]);
    for(char c = s[i]; c >= 'a'; c--) m[c] = 'a';
  }
  k -= int(mx - 'a');

  for(int i = p; i < n; i++) 
    for(char c = s[p]; c >= 'a'; c--) m[c] = min(m[c], char(c - k));

  for(auto i: s) cout << m[i];
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}