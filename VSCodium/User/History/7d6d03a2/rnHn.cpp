#include <bits/stdc++.h>
using namespace std;

int main() {
  string str; cin >> str;
  int n; cin >> n;
  int s = 0, r = 0;
  for (auto i : str) {
    if (i == 'S')s++;
    else r++;
  }
  int ans1 = r - s + (2 * min(n, s));
  ans1 = abs(ans1);

  if ((n - min(n, s)) & 1) ans1 -= 2;
  int ans2 = s - r + (2 * min(n, r));
  ans2 = abs(ans2);

  if ((n - min(n, r)) & 1) ans2 -= 2;

  cout << ans1 << ' ' << ans2 << endl;
  cout << max(ans1, ans2) << endl;
}
