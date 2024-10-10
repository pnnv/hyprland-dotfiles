#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <pair <int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  
  int A = 0, B = 0;
  for(auto &[x, y]: a) {
    if(x == -1 && y == -1) {
      A--; B--;
    } else if(x == 1 && y < 1) {
      A++;
    } else if(y == 1 && x < 1) {
      B++;
    } else if(x == y) {
      if(A < B) {
        A += x;
      } else {
        B += x;
      }
    }
  }

  cout << min(A, B) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}