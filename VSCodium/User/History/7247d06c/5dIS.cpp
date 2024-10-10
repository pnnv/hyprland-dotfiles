#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	int w = 0;
	if(a > c) w++;
	if(a > d) w++;
	if(b > c) w++;
	if(b > d) w++;
	cout << w << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}