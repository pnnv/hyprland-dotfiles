#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> cor(vector<vector<int>> matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> lu(n, vector<int>(m, 0)), ld(n, vector<int>(m, 0)), ru(n, vector<int>(m, 0)), rd(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                lu[i][j] = (i > 0 && j > 0) ? lu[i - 1][j - 1] + 1 : 1;
                ru[i][j] = (i > 0 && j < m - 1) ? ru[i - 1][j + 1] + 1 : 1;
            }
        }

    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                ld[i][j] = (i < n - 1 && j > 0) ? ld[i + 1][j - 1] + 1 : 1;
                rd[i][j] = (i < n - 1 && j < m - 1) ? rd[i + 1][j + 1] + 1 : 1;
            }
        }

    int max_size = 0, res_r = -1, res_c = -1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int size = min({lu[i][j], ld[i][j], ru[i][j], rd[i][j]});
            if (size > max_size) {
                max_size = size;
                res_r = i;
                res_c = j;
            }
        }

    return {res_r, res_c};
}
int main() {
	vector <vector <int>> mat = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

	auto i= cor(mat);

	cout << i[0] << ' ' << i[1] << endl;


}



// using namespace std;

// typedef long long ll;

// int main() {
// 	ios::sync_with_stdio(false); cin.tie(0);

// 	int n, k; cin >> n >> k;
// 	vector <ll> v(n), st(n);
// 	iota(st.begin(), st.end(), 0);

// 	for(auto &i: v) cin >> i;
// 	for(int i = 1; i < n; i++) v[i] += v[i - 1];
	
// 	auto ps = [&](int l, int r) {
// 		return (v[r] - (l == 0 ? 0 : v[l - 1]));
// 	};

// 	vector <ll> dp(n);
// 	dp[k - 1] = ps(0, k - 1), st[k - 1] = 0;

// 	for(int i = k; i < n; i++) {
// 		if(dp[i - 1] >= ps(i - k + 1, i)) 
// 			st[i] = st[i - 1], dp[i] = dp[i - 1];
// 		else
// 			dp[i] = ps(i - k + 1, i), st[i] = i - k + 1;
// 	}

	

// 	ll mx = 0;
// 	int a = -1, b = -1;

// 	for(int i = k; i <= n - k; i++)  {
// 		if(dp[i - 1] + ps(i, i + k - 1) > mx) {
// 			mx = dp[i - 1] + ps(i, i + k - 1);
// 			a = st[i - 1], b = i;
// 		}
// 	}

// 	cout <<  a + 1 << ' ' << b + 1 << endl;
// }
