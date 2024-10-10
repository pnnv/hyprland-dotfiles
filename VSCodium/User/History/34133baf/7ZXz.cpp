#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// Fenwick Tree (Binary Indexed Tree) implementation
class FenwickTree {
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int index, int delta) {
        for (; index < tree.size(); index += index & -index) {
            tree[index] += delta;
        }
    }

    int query(int index) const {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

private:
    vector<int> tree;
};

int countIntervalsInRange(vector<pair<int, int>>& intervals, int l, int r) {
    map<int, int> coord_map;
    for (const auto& interval : intervals) {
        coord_map[interval.first];
        coord_map[interval.second];
    }
    coord_map[l];
    coord_map[r];

    int idx = 0;
    for (auto& [key, value] : coord_map) {
        value = ++idx;
    }

    FenwickTree fenwick(idx);

    for (const auto& interval : intervals) {
        fenwick.update(coord_map[interval.first], 1);
        fenwick.update(coord_map[interval.second] + 1, -1);
    }

    int start = coord_map.lower_bound(l)->second;
    int end = coord_map.upper_bound(r)->second;
    return fenwick.query(end) - fenwick.query(start - 1);
}

int GetAnswer(int N, int Q, int C, vector <int> A, vector <vector <int>> P) {
	map <int, pair <int, int>> occ;
	for (int i = 0; i < N; i++) {
		if(occ.count(A[i])) {
			occ[A[i]].second = i + 1;
		} else {
			occ[A[i]].first = i + 1;
			occ[A[i]].second = i + 1;
		}
	}
	vector <pair <int, int>> I;
	for(auto &[a, b] : occ) {
		I.push_back({b.first, b.second});
	}

	sort(I.begin(), I.end());

	ll ans = occ.size() * Q;
	for(int i = 0; i < Q; i++) {
		int a = P[i][0], b = P[i][1];
		int pp = countIntervalsInRange(I, a, b);
		ans -= pp;
	}
	return ans;
}


void solve()
{
    ll n,q,c;
    cin>>n>>q>>c;
    vector <int>  a(n);
    for(auto &i: a) cin >> i;
    // SegTree tree = SegTree(n,a);
	vector <vector <int>> P(q);

    ll ans = 0;
    for(int i = 0; i < q; i++)
    {
        ll l,r;
        cin>>l>>r;
		P[i].push_back(l);
		P[i].push_back(r);
        
    }

	cout << GetAnswer(n, q, c, a, P) << endl;

}

int main() {
	solve();
}