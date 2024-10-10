#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector <int> v(12);
  for(auto &i: v) cin >> i;

  int a1x = v[0], a1y = v[1], a1z = v[2];
  int a2x = v[3], a2y = v[4], a2z = v[5];
  int b1x = v[6], b1y = v[7], b1z = v[8];
  int b2x = v[9], b2y = v[10], b2z = v[11];

  int aminx = std::min(a1x, a2x), amaxx = std::max(a1x, a2x);
  int aminy = std::min(a1y, a2y), amaxy = std::max(a1y, a2y);
  int aminz = std::min(a1z, a2z), amaxz = std::max(a1z, a2z);

  int bminx = std::min(b1x, b2x), bmaxx = std::max(b1x, b2x);
  int bminy = std::min(b1y, b2y), bmaxy = std::max(b1y, b2y);
  int bminz = std::min(b1z, b2z), bmaxz = std::max(b1z, b2z);

  bool overlap_x = (aminx <= bmaxx) && (amaxx >= bminx);
  bool overlap_y = (aminy <= bmaxy) && (amaxy >= bminy);
  bool overlap_z = (aminz <= bmaxz) && (amaxz >= bminz);

  bool intersect = overlap_x && overlap_y && overlap_z;

  cout << (intersect ? "Yes\n" : "No\n");
}