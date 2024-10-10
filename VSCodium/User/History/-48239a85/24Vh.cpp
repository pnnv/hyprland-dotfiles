#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
  int n; cin >> n;
  vector <ll> a(n), b(n), sa(n), sb(n), ma(n), mb(n);
  for(auto &i: a) cin >> i;
  for(auto &i: b) cin >> i;
  for (int i = 0; i < n; i++) sa[i] = i, sb[i] = i;
  sort(sa.begin(), sa.end(), [&](int x, int y) { return a[x] < a[y]; });
  sort(sb.begin(), sb.end(), [&](int x, int y) { return b[x] < b[y]; });
  for (int i = 0; i < n; i++) ma[i] = a[sb[i]], mb[i] = b[sa[i]];
  for(int i = n - 2; i >= 0; i--) ma[i] = min(ma[i], ma[i + 1]), mb[i] = min(mb[i], mb[i + 1]);

  int mna = a[sb[n - 1]], mnb = b[sa[n - 1]], ia = sb.back(), ib = sa.back();

  function <void(ll, bool)> fn = [&](ll x, bool f) {
    if(f) {
      ll l = b[sa[x]];
      int lo = -1, hi = n - 1;
      while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(b[sb[mid]] <= l) lo = mid;
        else hi = mid - 1;
      }
      if(ma[sb[lo]] < mna) {
        mna = ma[sb[lo]];
        ia = sb[lo];
        fn(sb[lo], false);
      } else return;
    } else {
      ll l = a[sb[x]];
      int lo = -1, hi = n - 1;
      while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(a[sa[mid]] <= l) lo = mid;
        else hi = mid - 1;
      }
      if(mb[sa[lo]] < mnb) {
        mnb = mb[sa[lo]];
        ia = sa[lo];
        fn(sa[lo], true);
      } else return;
    }
  };
  fn(n - 1, true); fn(n - 1, false);

  string s(n, '0');
  for(int i = ia; i < n; i++) s[sb[i]] = '1';
  for(int i = ib; i < n; i++) s[sa[i]] = '1';
  cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}