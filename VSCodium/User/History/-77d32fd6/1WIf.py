def max_subsegments_with_T_as_subsequence(S, T, K):
    N = len(S)
    M = len(T)

    # dp[i][j] will be the minimum changes to make T[:j] a subsequence of S[:i]
    dp = [[float('inf')] * (M + 1) for _ in range(N + 1)]

    for i in range(N + 1):
        dp[i][0] = 0

    for i in range(1, N + 1):
        for j in range(1, M + 1):
            if S[i - 1] == T[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + 1)

    max_subsegments = 0

    # Check all possible subsegments
    for start in range(N):
        for end in range(start + M - 1, N):
            if dp[end + 1][M] - dp[start][M] <= K:
                max_subsegments += 1

    return max_subsegments

# Example usage
S = "abcbad"
T = "ab"
K = 3
print(max_subsegments_with_T_as_subsequence(S, T, K))  # Should output 3
