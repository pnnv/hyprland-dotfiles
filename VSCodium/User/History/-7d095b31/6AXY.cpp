#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector <ll> v;
	for(int i = 1; i <= (n * n); i++)
		v.push_back(i);

	for(int i = 0; i < v.size() >> 1; i++)
		cout << v[i] << ' ' << v[v.size() - i - 1] << endl;
}