#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int getMinTime(int n, int m, vector <int> cache) {

  map <int, int> c;
  for(auto i: cache) c[i - 1]++;

  auto chk = [&](int mx) {
    vector <int> slot(n, mx);
    int ext = 0;
    for (int i = 0; i < n; i++) {
      int a = min(mx, c[i]);
      slot[i] -= a;
      ext += c[i] - a;
    }

    for (int i = 0; i < n; i++) {
      int rem = mx - slot[i];
      ext -= (rem / 2);
      if(ext <= 0) return true;
    }
    return false;
  };

  int lo = 0, hi = 4e5 + 1;
  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if(chk(mid)) hi = mid;
    else lo = mid + 1;
  }

  for(int i = 0; i < n; i++) {
    cout << chk(i) << ' ';
  }

  return lo;
}

int32_t main() {
  vector <int> cc = {1, 2, 3, 4};
  cout << getMinTime(4, 4, cc) << endl;  
}