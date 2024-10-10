#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c; cin >> a >> b >> c;
	if(b < c) {
		if(a < b || a > c) cout << "Yes\n";
		else cout  << "No\n"; 
	} else {
		if(a > c && a < b) cout << "Yes\n";
		else cout << "No\n";
	}
}