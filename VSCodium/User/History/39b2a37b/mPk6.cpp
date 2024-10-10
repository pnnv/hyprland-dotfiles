#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector <int> v(n);
    for(auto &i: v) cin >> i;
    int q; cin >> q;
    
    while(q--) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        for(int i = l - 1; i < r; i++) {
            if(v[i] % (r - l + 1) == 0) cnt++;
        }
        cout << cnt << endl;
    }
}
