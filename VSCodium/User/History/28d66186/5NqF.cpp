#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string v = "aeiou";
	string ans = "";
	for(int i = 0; i < 5; i++) {
		if(i < n % 5) ans += string((n / 5) + 1, v[i]); 
		else ans += string(n / 5, v[i]);
	}

	cout << ans << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}