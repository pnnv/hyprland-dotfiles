

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long int
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(x) cout << x << '\n';
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define yesno(ok) cout << (ok ? "YES" : "NO") << '\n';

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  map<int, int> f;

  for (auto &i : a)
    cin >> i, f[i]++;

  auto SQRT = [&](int num) {
    int lo = 0, hi = 1e9 + 10, res = -1;
    while (lo <= hi) {
      int mid = (lo + ((hi - lo) >> 1));

      if (1LL * mid * mid <= num) res = mid, lo = mid + 1;
      else hi = mid - 1;
    }
    return res;
  };

  auto findAns = [&](int x, int y) {
    int a = 1, b = -x, c = y;
    int D = b * b - 4LL * c;
    int sqt  = SQRT(D);

    if (D < 0 || (sqt * sqt) != D)
      return 0LL;

    int num1 = (x + sqt) / (2LL);
    int num2 = (x - sqt) / (2LL);

    if (num1 == num2)
      return (f[num1] * (f[num1] - 1LL) / 2LL);
    return f[num1] * f[num2];
  };

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << findAns(x, y) << " \n"[i == q - 1];
  }
}

/* ----------------------------------------- MAIN
 * --------------------------------------------------*/

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
