#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(int m, vector <string> s) {
	int ans = 0;

	for(int i = 0; i < s.size(); i++) {
		bool e = true;
		for(auto c: s[i]) {
			if(int(c) % 2 == 0) {
				e = false;
				break;
			}
		}
		if(e) ans++;
	}
	if(ans & 1) return "ODD";
	else return "EVEN";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cout << solve(74, {"azbde", "abcher", "acegk"});
}