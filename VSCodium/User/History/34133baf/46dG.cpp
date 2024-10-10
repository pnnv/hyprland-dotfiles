#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class K> using oset =  tree<K, null_type, less_equal<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
	oset <int> l, r;
	for(auto &[a, b] : occ) {
		l.insert(b.first);
		r.insert(b.second);
	}
	ll ans = occ.size() * Q;
	for(int i = 0; i < Q; i++) {
		int a = P[i][0], b = P[i][1];
		int pp = r.order_of_key(a) + (l.size() - l.order_of_key(b + 1));
		ans += (occ.size() - pp);
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