#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	string s; cin >> s;
	int n = s.size();
	map <int, int> f;
	map <char, int> ini;
	vector <int> l(26, -1), lex(26);
	iota(lex.begin(), lex.end(), 0);

	for (int i = 0; i < n; i++) 
		f[int(s[i] - 'a')]++, l[int(s[i] - 'a')] = i;	

	sort(lex.begin(), lex.end(), 
		[&](int a, int b) { return l[a] < l[b]; });

	string rem = "";
	for(auto i: lex)
		if(l[i] != -1) rem.push_back(char(i + 'a'));

	for(int i = 0; i < rem.size(); i++) {
		if(f[int(rem[i] - 'a')] % (i + 1) != 0 && cout << -1 << endl) return;
		ini[rem[i]] = f[int(rem[i] - 'a')] / (i + 1);
	}
	
	string t = "";
	{
		int i = 0;
		while(i < s.size() && !ini.empty()) {
			t.push_back(s[i]);
			ini[s[i]]--;
			if(ini[s[i]] == 0) ini.erase(s[i]);
			i++;
		}
		if(!ini.empty() && cout << -1 << endl) return;
	}

	
	string tmp = t;
	set <char> r;
	for(auto i: rem) {
		r.insert(i);
		for(auto j: t)
			if(!r.count(j)) tmp.push_back(j);
		if(tmp != s && cout  << -1 << endl) return;
	}

	cout  << t << ' ' << rem << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}