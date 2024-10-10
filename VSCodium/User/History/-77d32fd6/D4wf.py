def max_subsegments(S, T, K):
    N, M = len(S), len(T)
    dp = [[[0 for _ in range(M + 1)] for _ in range(K + 1)] for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for k in range(K + 1):
            for j in range(M + 1):
                # Not using current character
                dp[i][k][j] = dp[i-1][k][j]
                
                if j > 0:
                    if S[i-1] == T[j-1]:
                        # Matching without change
                        dp[i][k][j] = max(dp[i][k][j], dp[i-1][k][j-1])
                        if j == M:
                            # Completed a match
                            dp[i][k][j] = max(dp[i][k][j], dp[i-1][k][0] + 1)
                    if k > 0:
                        # Matching with change
                        dp[i][k][j] = max(dp[i][k][j], dp[i-1][k-1][j-1])
                        if j == M:
                            # Completed a match using a change
                            dp[i][k][j] = max(dp[i][k][j], dp[i-1][k-1][0] + 1)
    
    return max(dp[N][k][M] for k in range(K + 1))

S = "abcbad"
T = "ab"
K = 3
result = max_subsegments(S, T, K)
print(f"Maximum number of subsegments: {result}")