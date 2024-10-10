def max_subsegments_with_T_as_subsequence(S, T, K):
    N = len(S)
    M = len(T)

    # Function to check if T can be a subsequence of subsegment S[start:end+1] with at most K changes
    def can_make_subsequence_with_changes(start, end, K):
        # Create a DP table where dp[j] is the minimum number of changes needed to form T[:j] from S[start:end+1]
        dp = [float('inf')] * (M + 1)
        dp[0] = 0

        for i in range(start, end + 1):
            # Traverse T in reverse to prevent overwriting results for the current S[i]
            for j in range(M - 1, -1, -1):
                if S[i] == T[j]:
                    dp[j + 1] = min(dp[j + 1], dp[j])
                else:
                    dp[j + 1] = min(dp[j + 1], dp[j] + 1)
        
        return dp[M] <= K

    count = 0

    # Check all subsegments of S
    for start in range(N):
        for end in range(start + M - 1, N):
            if can_make_subsequence_with_changes(start, end, K):
                count += 1

    return count

# Example usage
S = "abcbad"
T = "ab"
K = 3
print(max_subsegments_with_T_as_subsequence(S, T, K))  # Expected output: 3
