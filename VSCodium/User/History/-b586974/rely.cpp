#include <bits/stdc++.h>
#include <sys/resource.h> // Include this for setrlimit

using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); 
    for(int i = 0; i < n; i++) 
        cin >> a[i] >> b[i];

    ld lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        hi = max(hi, ld(i + ld(1)) / b[i]);
    }
    for (int i = 0; i < n; i++) {
        if((ld(i + ld(1)) / hi) < a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << hi << endl;
}

int main() {
    // Increase stack size (Linux)
    const rlim_t kStackSize = 1024 * 1024 * 1024; // 1 GB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                cerr << "setrlimit returned result = " << result << endl;
            }
        }
    }

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}