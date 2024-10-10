#include <bits/stdc++.h>
#include <iterator>
using namespace std;

typedef long long ll;

class DSU {
public:
    vector<int> parent, rank;
    vector<set<int>> sets;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        sets.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            sets[i].insert(i); // Initially, each set contains only the node itself
        }
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY); // Always merge smaller set into larger
            }
            parent[rootY] = rootX;
            
            // Merge smaller set into larger set
            if (sets[rootX].size() < sets[rootY].size()) {
                swap(sets[rootX], sets[rootY]);
            }
            sets[rootX].insert(sets[rootY].begin(), sets[rootY].end());
            sets[rootY].clear();

            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }

    const set<int>& getSet(int x) {
        return sets[find(x)];
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
			int p = d.find(u - 1);
			auto st = d.getSet(p);
			if(st.size() < v && cout << -1 << endl) continue;
			auto _ = st.rbegin();
			for(int j = 1; j < v; j++) ++_;
			cout << *_ + 1 << endl;
		}
	}
}