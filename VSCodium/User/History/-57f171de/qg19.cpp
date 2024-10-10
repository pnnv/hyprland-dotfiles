#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;

	function <int(char a, string t)> rec = [&](char c, string t) {
		if(t.size() == 1) return (t[0] == c ? 0 : 1);
		int cur = 0;
		for(int i = 0; i < t.size() / 2; i++)
			if(t[i] != c) cur++;
		int pp = cur + rec(c + 1, t.substr(t.size() / 2, t.size() / 2));
		cur = 0;
		for(int i = t.size() / 2; i < t.size(); i++)
			if(t[i] != c) cur++;
		pp = min(pp, cur + rec(c + 1, t.substr(0, t.size() / 2)));
		return pp;
	};
	cout << rec('a', s) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}