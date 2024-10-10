def max_subsegments(S, T, K):
    N, M = len(S), len(T)
    dp = [[[0 for _ in range(M + 1)] for _ in range(K + 1)] for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for j in range(K + 1):
            for k in range(M + 1):
                dp[i][j][k] = dp[i-1][j][k]
                if k > 0:
                    if S[i-1] == T[k-1]:
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + (1 if k == M else 0))
                    if j > 0:
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1] + (1 if k == M else 0))
    
    return max(dp[N][j][M] for j in range(K + 1))

S = "abacbd"
T = "ab"
K = 3
result = max_subsegments(S, T, K)
print(f"Maximum number of subsegments: {result}")
