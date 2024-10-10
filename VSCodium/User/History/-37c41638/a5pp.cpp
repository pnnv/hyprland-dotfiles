#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	set <string> st;

	sort(s.begin(), s.end());

	auto isp = [&](string p) {
		int sp = p.size();
		for(int i = 0; i < (sp >> 1); i++)
			if(p[i] != p[sp - i - 1]) return false;
		return true;
	};

	do {
		bool pp = true;
		for(int i = 0; i <= n - k; i++) {
			if(isp(s.substr(i, k))) {
				pp = false;
				break;
			}
		}
		if(pp) st.insert(s);
	} while(next_permutation(s.begin(), s.end()));

	cout << st.size() << endl;
}