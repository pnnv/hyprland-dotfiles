def max_subsegments_with_T_as_subsequence(S, T, K):
    N = len(S)
    M = len(T)
    
    # Function to calculate the minimum changes needed to make T a subsequence of S[start:end+1]
    def min_changes_to_subsequence(S, T):
        N = len(S)
        M = len(T)
        dp = [[float('inf')] * (M + 1) for _ in range(N + 1)]
        
        for i in range(N + 1):
            dp[i][0] = 0
        
        for i in range(1, N + 1):
            for j in range(1, M + 1):
                if S[i - 1] == T[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + 1)
        
        return dp[N][M]
    
    max_subsegments = 0
    
    # Iterate over all possible subsegments of S
    for start in range(N):
        for end in range(start + M - 1, N):
            subsegment = S[start:end + 1]
            if min_changes_to_subsequence(subsegment, T) <= K:
                max_subsegments += 1
    
    return max_subsegments

# Example usage
S = "abcbad"
T = "ab"
K = 3
print(max_subsegments_with_T_as_subsequence(S, T, K))  # Should output 3
