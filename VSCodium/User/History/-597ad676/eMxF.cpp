#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	vector <ll> v(6);
	for(auto &i: v) cin >> i;
	
	vector <ll> c;
	c.push_back((v[0] - v[2]) * (v[0] - v[2]) + ((v[1] - v[3]) * (v[1] - v[3])));
	c.push_back((v[0] - v[4]) * (v[0] - v[4]) + ((v[1] - v[5]) * (v[1] - v[5])));
	c.push_back((v[2] - v[4]) * (v[2] - v[4]) + ((v[3] - v[5]) * (v[3] - v[5])));
	sort(c.begin(), c.end());
	cout << (c[0] + c[1] == c[2] ? "Yes\n" : "No\n");
}