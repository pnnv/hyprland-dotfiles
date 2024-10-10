#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	vector<vector<vector<int>>> arr(n, vector<vector<int>>(n, vector<int>(n, 0)));

	for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            for (int k = 0; k < n; ++k) 
                cin >> arr[i][j][k];
	vector<vector<vector<int>>> prefixSum(n, vector<vector<int>>(n, vector<int>(n, 0)));

	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                prefixSum[i][j][k] = arr[i][j][k];
                if (i > 0) prefixSum[i][j][k] += prefixSum[i-1][j][k];
                if (j > 0) prefixSum[i][j][k] += prefixSum[i][j-1][k];
                if (k > 0) prefixSum[i][j][k] += prefixSum[i][j][k-1];
                if (i > 0 && j > 0) prefixSum[i][j][k] -= prefixSum[i-1][j-1][k];
                if (i > 0 && k > 0) prefixSum[i][j][k] -= prefixSum[i-1][j][k-1];
                if (j > 0 && k > 0) prefixSum[i][j][k] -= prefixSum[i][j-1][k-1];
                if (i > 0 && j > 0 && k > 0) prefixSum[i][j][k] += prefixSum[i-1][j-1][k-1];
            }
        }
    }

	auto query = [&](int x1, int y1, int z1, int x2, int y2, int z2) -> int {
        int result = prefixSum[x2][y2][z2];
        if (x1 > 0) result -= prefixSum[x1-1][y2][z2];
        if (y1 > 0) result -= prefixSum[x2][y1-1][z2];
        if (z1 > 0) result -= prefixSum[x2][y2][z1-1];
        if (x1 > 0 && y1 > 0) result += prefixSum[x1-1][y1-1][z2];
        if (x1 > 0 && z1 > 0) result += prefixSum[x1-1][y2][z1-1];
        if (y1 > 0 && z1 > 0) result += prefixSum[x2][y1-1][z1-1];
        if (x1 > 0 && y1 > 0 && z1 > 0) result -= prefixSum[x1-1][y1-1][z1-1];
        return result;
    };

	int q; cin >> q;

	for(;q--;) {
		int x1, x2, y1, y2, z1, z2; cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
		cout << query(x1, y1, z1, x2, y2, z2) << endl;
	}
}