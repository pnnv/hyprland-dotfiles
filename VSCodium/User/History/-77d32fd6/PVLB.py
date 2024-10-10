def max_subsegments(S, T, K):
    N = len(S)
    dp = [[0 for _ in range(K + 1)] for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for k in range(K + 1):
            dp[i][k] = dp[i-1][k]
            if S[i-1] == T[0]:
                dp[i][k] = max(dp[i][k], dp[i-1][k] + 1)
            if k > 0:
                dp[i][k] = max(dp[i][k], dp[i-1][k-1] + 1)
    
    return max(dp[N])

S = "abc"
T = "d"
K = 1
result = max_subsegments(S, T, K)
print(f"Maximum number of subsegments: {result}")