#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	string a, b; cin >> a >> b;
	queue <pair <char, int>> q;
	vector <pair <int, char>> op;

	for(int i = 0; i <= n - k; i++) {
		while(q.front().second == 0 && !q.empty()) q.pop();
		if(!q.empty()) q.front().second--;
		char cur = (q.empty() ? a[i] : q.front().first);
		a[i] = cur;
		if(cur != b[i]) {
			a[i] = b[i];
			int p = i;
			while(p > 0 && a[p] == b[i] && (i - p + 1) < k) p--;
			p++;
			q.push({b[i], k - 1 - (i - p)});
			op.push_back({p + 1, b[i]});
		} 
		// else {
			// if(b[i + k - 1] == a[i] && a[i + k - 1] != b[i + k - 1]) {
				// q.push({b[i], k - 1});
				// op.push_back({i + 1, b[i]});
			// }
		// }
	}
	
	for(int i = n - k + 1; i < n; i++) {
		while(q.front().second == 0 && !q.empty()) q.pop();
		if(!q.empty()) {
			a[i] = q.front().first;
			q.front().second--;
		}
	}

	if(a != b) {
		char c = a[n - k];
		for(int i = n - k + 1; i < n; i++)
			if(b[i] != c && cout << -1 << endl) return;
		op.push_back({n - k + 1, c});
	}
	cout << op.size() << endl;
	for(auto i: op) cout << i.first << ' ' << i.second << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}