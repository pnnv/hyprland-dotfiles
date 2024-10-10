#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
    ll n, m, N = 1e5 + 5;
    scanf("%lld %lld", &n, &m);
    ll mx = 0, fin = (m * (m + 1LL) / 2LL);
    vector<vector<int>> v(N);
    set<int> st;

    for (int _ = 0; _ < n; _++) {
        int l;
        scanf("%d", &l);
        st.clear();
        for (int j = 0; j < l; j++) {
            int xx;
            scanf("%d", &xx);
            st.insert(xx);
        }
        int a = -1, b = -1;
        for (int i = 0; i <= l + 2; i++) {
            if (!st.count(i)) {
                if (a == -1)
                    a = i;
                else {
                    b = i;
                    break;
                }
            }
        }
        v[b].push_back(a);
    }

    int i;
    vector<bool> taken(N, false);

    function<void(int)> f = [&](int c) {
        if (v[c].size() > 1) mx = i;
        if (c <= m && !taken[c]) {
            fin -= c;
            fin += i;
            taken[c] = true;
        }
        for (auto u : v[c])
            if (!taken[u]) f(u);
    };

    for (int cur = N - 1; cur >= 0; cur--) {
        if (taken[cur]) continue;
        i = cur;
        f(cur);
        if (mx != 0) break;
    }
    for (int j = 0; j < mx; j++)
        if (!taken[j]) fin -= j, fin += mx;

    printf("%lld\n", fin);
}

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) snu();
}
