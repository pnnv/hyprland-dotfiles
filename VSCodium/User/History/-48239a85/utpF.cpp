#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  ll n; cin >> n;
  vector <ll> a(n), b(n);
  ll ia = -1, mxa = 0, ib = -1, mxb = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] > mxa) {
      mxa = a[i];
      ia = i;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if(b[i] > mxb) {
      mxb = b[i];
      ib = i;
    }
  }
  ll lob = b[ia], loa = a[ib];
  string s(n, '0'); s[ia] = '1'; s[ib] = '1';
    
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}