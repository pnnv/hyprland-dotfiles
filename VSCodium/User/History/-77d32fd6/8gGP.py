def max_subsegments(S, T, K):
    N, M = len(S), len(T)
    dp = [[0] * (K + 1) for _ in range(N + 1)]
    
    for i in range(1, N + 1):
        for k in range(K + 1):
            # Copy the previous state
            dp[i][k] = dp[i-1][k]
            
            # Try matching the current character
            if S[i-1] == T[0]:
                dp[i][k] += 1
            
            # Try changing the current character
            if k > 0:
                dp[i][k] = max(dp[i][k], dp[i-1][k-1] + 1)
            
            # If we can form T, add the count from M positions back
            if i >= M:
                dp[i][k] += dp[i-M][k]
                if k > 0:
                    dp[i][k] = max(dp[i][k], dp[i-M][k-1] + 1)
    
    return dp[N][K]

S = "abcbad"
T = "ab"
K = 3
result = max_subsegments(S, T, K)
print(f"Maximum number of subsegments: {result}")