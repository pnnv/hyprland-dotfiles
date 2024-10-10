def can_achieve_score(s, k, target_score):
    flips = 0
    count = 0
    for i in range(len(s)):
        if i == 0 or s[i] == s[i-1]:
            count += 1
        else:
            count = 1
        
        if count == target_score:
            flips += 1
            count = 0
    
    return flips <= k

def min_score_binary_search(s, k):
    left, right = 1, len(s)
    
    while left < right:
        mid = (left + right) // 2
        if can_achieve_score(s, k, mid):
            right = mid
        else:
            left = mid + 1
    
    return left

# Example usage
s = "aaaaa"
k = 1
print(min_score_binary_search(s, k))