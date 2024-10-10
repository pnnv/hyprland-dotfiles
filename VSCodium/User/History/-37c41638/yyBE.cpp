#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	set <string> st;
	ll ans = 0;

	sort(s.begin(), s.end());

	do {
		bool pp = true;
		for(int i = 0; i <= n - k; i++) {
			bool pal = true;
			for(int j = 0; j < k / 2; j++) {
				if(s[i + j] != s[i + k - 1 - j]) {
					pal = false;
					break;
				}
			}
			if(pal) {
				pp = false; break;
			}
		}
		if(pp) ans++;
	} while(next_permutation(s.begin(), s.end()));

	cout << ans << endl;
}