#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    cin >> m;
    vector<int> s(m);
    for (int i = 0; i < m; ++i) cin >> s[i];

    sort(t.begin(), t.end());
    sort(s.begin(), s.end());

    int low = 0, high = 1e9, ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int j = 0;
        for (int i = 0; i < m; ++i) {
            int l = s[i] - mid, r = s[i] + mid;
            while (j < n && t[j] >= l && t[j] <= r) {
                j++;
            }
        }
        if (j == n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
