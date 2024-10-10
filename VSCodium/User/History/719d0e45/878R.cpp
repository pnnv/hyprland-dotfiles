#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  ll a, b, x, y; cin >> a >> b >> x >> y;
  ll d = abs(b - y);
  
  if((a + b) % 2 == 0) {
    if(x < a) {
      if(d >= (a - x) && cout << d << endl) return 0;
      ll pp = a - x; pp -= d;
      d += (pp + 1LL) / 2LL;
      cout << d << endl;
    } else {
      if(d >= (x - a) && cout << d << endl) return 0;
      ll pp = x - a; pp -= d;
      d += pp / 2LL;
      cout << d << endl;
    }
  } else {
    if(x < a) {
      if(d >= (a - x) && cout << d << endl) return 0;
      ll pp = a - x; pp -= d;
      d += (pp) / 2LL;
      cout << d << endl;
    } else {
      if(d >= (x - a) && cout << d << endl) return 0;
      ll pp = x - a; pp -= d;
      d += (pp + 1LL)/ 2LL;
      cout << d << endl;
    }
  }
}