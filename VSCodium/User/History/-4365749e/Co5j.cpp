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
		if(cur != b[i]) {
			q.push({b[i], k - 1});
			op.push_back({i + 1, b[i]});
		}
	}
	
	for(int i = n - k + 1; i < n; i++) {
		while(q.front().second == 0 && !q.empty()) q.pop();
		if(q.front().first != b[i] && cout << -1 << endl) return;
		if(!q.empty()) q.front().second--;
	}

	cout << op.size() << endl;

}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}