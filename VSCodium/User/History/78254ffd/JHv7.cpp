#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair <ll, ll>> factor(long long n) {
  vector<long long> factorization;
  for (int d : {2, 3, 5}) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
  int i = 0;
  for (long long d = 7; d * d <= n; d += increments[i++]) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
    if (i == 8)
      i = 0;
  }
  if (n > 1) factorization.push_back(n);
  vector <pair <ll, ll>> fx;
  map <ll, ll> pp;
  for(auto i: factorization) pp[i]++;
  for(auto i: pp) fx.push_back({i.first, i.second});
  return fx;
}

void snu() {
  ll n; cin >> n;
  auto fx = factor(n);
  if(fx.size() == 3) {
    for(auto i: fx) if(i.second != 2 && cout << "No\n") return;
    cout << "Yes\n"; return;
  }
  cout << "No\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}