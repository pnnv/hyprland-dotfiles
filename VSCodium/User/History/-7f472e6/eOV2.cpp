#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    vector<ll> x(n), p(n);
    for(auto &i: x) cin >> i;
    for(auto &i: p) cin >> i;

    for(int i = 1; i < n; i++) p[i] += p[i - 1];

    int q; cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;

        int a = lower_bound(x.begin(), x.end(), l) - x.begin();
        int b = lower_bound(x.begin(), x.end(), r + 1) - x.begin();

        if(b <= a) {
            cout << 0 << endl;
        } else {
            cout << (p[b - 1] - (a != 0 ? p[a - 1] : 0LL)) << endl;
        }
    }
}
