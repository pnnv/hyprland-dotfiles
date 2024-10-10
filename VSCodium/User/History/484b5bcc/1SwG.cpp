#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector <int> v(n);
	for(auto &i: v) cin >> i;
	for(int i = n - k; i  < n; i++) cout << v[i] << ' ';
	for(int i = 0; i < n - k; i++) cout << v[i] << ' ';
	cout << endl;
}