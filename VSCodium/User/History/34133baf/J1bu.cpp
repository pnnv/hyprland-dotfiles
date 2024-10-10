#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class K> using oset =  tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

int countIntervalsInRange(const vector<pair<int, int>>& intervals, int l, int r) {
    int count = 0;
    for (const auto& interval : intervals) {
        if (interval.first >= l && interval.second <= r) {
            count++;
        }
    }
    return count;
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