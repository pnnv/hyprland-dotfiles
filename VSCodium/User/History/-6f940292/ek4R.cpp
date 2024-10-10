// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;


// #include <bits/stdc++.h>

// long long minArea(vector<int>& x, vector<int>& y, int k) {
//     int n = x.size();
//     long long min_a = LLONG_MAX;
//     vector<pair<int, int>> p(n);

//     for (int i = 0; i < n; ++i) p[i] = {x[i], y[i]};

//     sort(p.begin(), p.end());

//     for (int l = 0; l < n; ++l) {
//         for (int r = l; r < n; ++r) {
//             vector<int> ys;
//             for (int i = l; i <= r; ++i) ys.push_back(p[i].second);

//             sort(ys.begin(), ys.end());

//             for (int t = 0; t <= ys.size() - k; ++t) {
//                 int b = t + k - 1;
//                 long long s = max(1LL * p[r].first - p[l].first, 1LL * ys[b] - ys[t]);
//                 min_a = min(min_a, s * s);
//             }
//         }
//     }

//     return min_a;
// }

// int32_t main() {
// 	int n; cin >> n;
// 	vector <int> x(n);
// 	vector <int> y(n);
// 	for(auto &i: x) cin >> i;
// 	cin >> n;
// 	for(auto &i: y) cin >> i;
// 	int k; cin >> k;
// 	cout << minArea(x, y, k);
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long minArea(vector<int>& x, vector<int>& y, int k) {
    int n = x.size();
    long long min_a = LONG_LONG_MAX;
    vector<pair<long long, long long>> p(n);

    for (int i = 0; i < n; ++i) p[i] = {x[i], y[i]};

    sort(p.begin(), p.end());

    vector<long long> ys;

    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            ys.clear();
            for (int i = l; i <= r; ++i) ys.push_back(p[i].second);

            sort(ys.begin(), ys.end());
			if(ys.size() < k) continue;

            for (int t = 0; t <= ys.size() - k; ++t) {
                int b = t + k - 1;
                long long s = max({1LL * (p[r].first - p[l].first + 2LL), 1LL * (ys[b] - ys[t] + 2LL)});
                min_a = min(min_a, s * s);
            }
        }
    }

    return min_a;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    cout << minArea(x, y, k) << endl;
    return 0;
}
