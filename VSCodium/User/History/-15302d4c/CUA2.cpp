#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <pair <int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;

  int pos = 0, neg = 0;

  int A = 0, B = 0;
  for(auto &[x, y]: a) {
    if(x >= 0 && y < 1) {
      A++;
    } else if(y >= 0 && x < 1) {
      B++;
    } else if(x == y) {
      if(x == -1 && y == -1) neg++;
      else if(x == 1 && y == 1) pos++;
    }
  }
  cout << A << ' ' << B << ' ';

  if(A < B) swap(A, B);
  if(A - B <= pos) {
    pos -= (A - B);
    B = A;
    A += pos / 2;
    B += pos / 2;
    if(pos & 1) A++;
  } else {
    B += pos;
  }

  if(A - B <= neg) {
    neg -= (A - B);
    A = B;
    A -= neg / 2;
    B -= neg / 2;
    if(neg & 1) B--;
  } else {
    A -= neg;
  }

  cout << min(A, B) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}