#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sol(vector <string>  p, int m) {
	int ans = 0;
	for(int i = 0; i < m; i++) {
		set <char> st;
		for(int j = 0; j < p.size(); j++) 
			st.insert(p[j][i]);
		string tmp = "";
		for(auto c: st) tmp.push_back(c);

		if(tmp.size() > 2) ans++;
		else if(tmp.size() == 2) {
			if(tmp[0] != '?') ans++;
		}
	}

	return ans;
}

vector <int> distinctOrder(int n, vector <int> &U, vector <int> &V) {
	vector <vector <int>> adj(n + 1);
	for(int i = 0; i < U.size(); i++) {
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}
	
	for (int i = 1; i <= n; i++) 
		sort(adj[i].rbegin(), adj[i].rend());
	
	vector <int> order, vis(n + 1, 0);

	function <void (int)> dfs = [&](int cur) {
		vis[cur] = 1;
		order.push_back(cur);
		for(auto nbr: adj[cur]) {
			if(vis[nbr] == 0) 
				dfs(nbr);
		}
	};
	dfs(1);
	vector <int> ans;
	map <int, int> found;

	for(auto node: order) {
		if(found[node] == 0) {
			ans.push_back(node);
		}
		found[node] = 1;
	}

	return ans;
}

void snu() {
	vector <string> s = {"abcd", "a?cd", "am?d", "????"};
	cout << sol(s, 4) << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	snu();
}