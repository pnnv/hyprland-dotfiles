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

  int mna = a[sa.back()], mnb = b[sb.back()];
  int ta = mna, tb = 1e9 + 1;

  function <void(int, bool)> fn = [&](int l, bool f) {
    if(f) {
      int lo = -1, hi = n - 1;
      while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(a[sa[mid]] <= l) lo = mid;
        else hi = mid - 1;
      }
      if(mb[lo] < tb) {
        tb = mb[lo]; fn(tb, false);
      } else return;
    } else {
      int lo = -1, hi = n - 1;
      while(lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if(b[sb[mid]] <= l) lo = mid;
        else hi = mid - 1;
      }
      if(ma[lo] < ta) {
        ta = ma[lo]; fn(ta, true);
      } else return;
    }
  }; fn(mna, true);
  mna = min(mna, ta); mnb = min(mnb, tb);
  ta = 1e9 + 1, tb = b[sb.back()];
  fn(mnb, false);
  mna = min(mna, ta); mnb = min(mnb, tb);

  string s(n, '0');
  for (int i = 0; i < n; i++) 
    if(a[i] >= mna || b[i] >= mnb) s[i] = '1';
  cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}