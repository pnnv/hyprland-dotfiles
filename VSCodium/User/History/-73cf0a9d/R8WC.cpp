#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	s[0] = '(';
	int x = 0;
	for(auto &i: s) {
		if(i == '(') x++;
		else if(i == ')') x--;
		else {
			if(x > 0) {
				i = ')'; x--;
			} else {
				i = '('; x++;
			}
		}
	}
	stack <int> st;
	ll xx = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '(') st.push(i);
		else {
			int pp = st.top();
			st.pop(); xx += i - pp;
		}
	}

	cout << xx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}