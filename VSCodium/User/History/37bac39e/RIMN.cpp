#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int y; cin >> y;
	if(y % 400 == 0) cout << 366;
	else if(y % 100 == 0) cout << 365;
	else if(y % 4 == 0) cout << 366;
	else cout << 365;
}