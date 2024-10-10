#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n, k; cin >> n >> k;
  vector <int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int op = 0;
  for (int i = 0; i < k; i++) {
    if(v[i] == 0) {
      k++; continue;
    }
    bool f = true;
    for(int j = i + 1; j < v.size(); j++) {
      if(v[j] < v[i]) {
        v[i] = 0; v[j] = 0; f = false; break;
      }
    }
    if(f) continue;
    for(int j = i + 1; j < v.size(); j++) {
      if(v[j] <= v[i]) {
        op++; v[i] = 1;
        v[j] = 0; break;
      }
    }
  }

  for (int i = 0; i < n; i++) op += v[i];
  cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}