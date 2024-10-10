#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

ll minCost(vector<ll>& v, vector<ll>& c) {
    ll n = v.size(), res = 0;
    vector<pair<ll, ll>> p(n);
    for (ll i = 0; i < n; ++i) p[i] = {v[i], c[i]};
    sort(p.begin(), p.end(), [&](pair <ll, ll> a, pair <ll, ll>  b)  {
		if(a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	});

    set<ll> used;
    used.insert(p[0].first);

    for (ll i = 1; i < n; ++i) {
        ll x = p[i].first;
        while (used.count(x)) {
            x++;
            res += p[i].second;
        }
        used.insert(x);
    }
    return res;
}

int main() {
    vector<ll> v = {8, 6, 9};
    vector<ll> c = {9, 5, 7};
    cout << minCost(v, c) << endl;
    return 0;
}
