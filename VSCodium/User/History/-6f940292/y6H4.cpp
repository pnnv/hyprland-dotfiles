#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin >> str;
	int n; cin >> n;
	int s = 0, r = 0;
	for(auto i: str) {
		if(i == 'S') s++;
		else r++;
	}
	if(s > r) swap(s, r);
	int ans = r - s;

	ans += 2 * min(n, s);

	cout << ans << endl;
}