#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int minCost(vector<int>& v, vector<int>& c) {
    int n = v.size(), res = 0;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) p[i] = {v[i], c[i]};
    sort(p.begin(), p.end(), [&](pair <int, int> a, pair <int, int>  b)  {
		if(a.first != b.first) return a.first < b.first;
		else return a.second > b.second;
	});

    set<int> used;
    used.insert(p[0].first);

    for (int i = 1; i < n; ++i) {
        int x = p[i].first;
        while (used.count(x)) {
            x++;
            res += p[i].second;
        }
        used.insert(x);
    }
    return res;
}

int main() {
    vector<int> v = {1, 2, 2, 2, 3};
    vector<int> c = {1, 5, 2, 3, 4};
    cout << minCost(v, c) << endl;
    return 0;
}
