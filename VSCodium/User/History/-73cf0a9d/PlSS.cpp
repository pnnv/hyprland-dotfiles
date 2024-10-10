#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	s[0] = '(';
	int x = 0;
	for(auto &i: s) {
		if(s[i] == '(') x++;
		else if(s[i] == ')') x--;
		else {
			if(x > 0) {
				i = ')'; x--;
			} else {
				i = '('; x++;
			}
		}
	}
	cout << s << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}