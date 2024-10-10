#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	ll fin = 0;
	int n; cin >> n;
	vector <vector <int>> v(n + 1, vector <int> (2));
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; v[a][b]++;
	}
	ll tmp = 0;
	for (int i = 0; i <= n; i++) {
		if(v[i][1] == 1 && v[i][0] == 1) fin += tmp;
		if(v[i][1] == 1) tmp++;
	}
	tmp = 0;
	for (int i = n; i >= 0; i--) {
		if(v[i][1] == 1 && v[i][0] == 1) fin += tmp;
		if(v[i][1] == 1) tmp++;
	}
	tmp = 0;
	for (int i = 0; i <= n; i++) {
		if(v[i][1] == 1 && v[i][0] == 1) fin += tmp;
		if(v[i][0] == 1) tmp++;
	}
	tmp = 0;
	for (int i = n; i >= 0; i--) {
		if(v[i][1] == 1 && v[i][0] == 1) fin += tmp;
		if(v[i][0] == 1) tmp++;
	}

	for(int i = 1; i < n; i++) {
		if(v[i][0] == 1 && v[i - 1][1] == 1 && v[i + 1][1] == 1) fin++;
		if(v[i][1] == 1 && v[i - 1][0] == 1 && v[i + 1][0] == 1) fin++;
	}

	cout << fin << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}