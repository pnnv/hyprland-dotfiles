#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Helper function to calculate minimum changes needed to make T a subsequence of a substring of S
int minChangesToMakeSubsequence(const string& S, const string& T, int start, int end) {
    int N = end - start + 1;
    int M = T.length();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));

    for (int i = 0; i <= N; ++i) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (S[start + i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[N][M];
}

int maxSubsegmentsWithTAsSubsequence(string S, string T, int K) {
    int N = S.length();
    int count = 0;

    // Check each possible subsegment
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (minChangesToMakeSubsequence(S, T, i, j) <= K) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string S = "abcabc";
    string T = "abc";
    int K = 1;

    cout << maxSubsegmentsWithTAsSubsequence(S, T, K) << endl; // Output should be correct based on the example test case

    return 0;
}
