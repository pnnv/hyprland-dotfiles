#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubsegmentsWithTAsSubsequence(string S, string T, int K) {
    int N = S.length();
    int M = T.length();

    // Initialize dp array
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 0;
    }

    // Fill dp array
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    // Count valid subsegments
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            if (dp[j][M] <= K) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string S = "abs";
    string T = "d";
    int K = 1;

    cout << maxSubsegmentsWithTAsSubsequence(S, T, K) << endl;

    return 0;
}
