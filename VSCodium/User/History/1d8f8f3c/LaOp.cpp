#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	char a, b, c; cin >> a >> b >> c;
	if(a == b) {
		if(c == '<') cout << 'B';
		else cout << 'C';
	} else cout << "A";
}