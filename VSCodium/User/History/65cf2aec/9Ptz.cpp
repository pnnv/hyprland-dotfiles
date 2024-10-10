#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int r, g, b; cin >> r >> g >> b;
	string s; cin >> s;
	if(s.front() == 'R') cout << min(g, b);
	else if(s.front() == 'G') cout << min(r, b);
	else cout << min(r, g);
}