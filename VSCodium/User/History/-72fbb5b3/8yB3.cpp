#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector <int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

  int n; cin >> n;
  vector <int> c(71);
  for (int i = 0; i < n; i++) {
    int x; cin >> x; c[x]++;
  }

  vector <ll> fo(71), fe(71);

  
}