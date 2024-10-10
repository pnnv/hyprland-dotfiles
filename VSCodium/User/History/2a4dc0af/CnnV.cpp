#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(NULL) -> ios::sync_with_stdio(0);
    int n; cin >> n;
    set <pair <int, int>> bad;
    vector <vector <int>> g(n);

    for(int i = 0; i < n - 1; i++) {
        int x, y, t; cin  >> x >> y >> t;
        g[--x].push_back(--y);
        g[y].push_back(x);
        if(t == 2) {
            bad.insert({x, y});
            bad.insert({y, x});
        }
    }
	
	
}
