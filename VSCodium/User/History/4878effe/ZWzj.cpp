#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	string s; cin >> s;
	while(s.back() == '0' && s.size() > 1) s.pop_back();
	if(s.back() == '.') s.pop_back();
	cout  << s;
}