#include <bits/stdc++.h>
#include <iterator>
using namespace std;

typedef long long ll;


struct DSU {
    vector<int> parent, size;
    vector<multiset<int>> top10;

    DSU(int n) : parent(n), size(n, 1), top10(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            top10[i].insert(i); 
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void mergeTop10(multiset<int> &a, multiset<int> &b) {
        for (int v : b) {
            a.insert(v);
            if (a.size() > 10) a.erase(a.begin());
        }
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
            mergeTop10(top10[u], top10[v]);
        }
    }

    int kthLargest(int u, int k) {
        u = find(u);
        if (k > top10[u].size()) return -1; 
        auto it = top10[u].rbegin();
        advance(it, k - 1);
        return *it;
    }
};


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, q; cin >> n >> q;
	DSU d(n);
	

	while(q--) {
		int t, u, v; cin >> t >> u >> v;
		if(t == 1) {
			d.unite(u - 1, v - 1);
		} else {
			int p = d.kthLargest(u - 1, v);
			cout << (p == -1 ? p : p + 1) << endl;
		}
	}
}