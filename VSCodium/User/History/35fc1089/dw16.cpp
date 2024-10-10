#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;

  for(int i = 1; i <= n / 2; i++) 
    cout << i << ' ' << ((n + (!(n & 1))) - i) << ' ';
  if(n & 1) cout << n << ' ';
  cout << endl;

}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}