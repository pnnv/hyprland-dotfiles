#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	int n = s.size();
	map <int, int> f, ini;
	vector <int> l(26, -1), lex(26);
	iota(lex.begin(), lex.end(), 0);

	for (int i = 0; i < n; i++) 
		f[int(s[i] - 'a')]++, l[int(s[i] - 'a')] = i;	

	sort(lex.begin(), lex.end(), 
		[&](int a, int b) { return l[a] < l[b]; });

	string rem = "";
	for(auto i: lex)
		if(l[i] != -1) rem.push_back(char(i + 'a'));

	cout << rem << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}