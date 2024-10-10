#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100000

bool canAchieveScore(const char *s, int k, int L) {
    int n = strlen(s);
    
    // Check for target character 'a'
    int flips = 0;
    for (int i = 0; i < n; i++) {
        if (i >= L) {
            if (s[i - L] == 'a') flips--;
        }
        if (s[i] == 'b') flips++;
        if (i >= L - 1 && flips <= k) return true;
    }
    
    // Check for target character 'b'
    flips = 0;
    for (int i = 0; i < n; i++) {
        if (i >= L) {
            if (s[i - L] == 'b') flips--;
        }
        if (s[i] == 'a') flips++;
        if (i >= L - 1 && flips <= k) return true;
    }
    
    return false;
}

int minPossibleScore(const char *s, int k) {
    int low = 1, high = strlen(s);
    int result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAchieveScore(s, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    char s[MAX_LEN];
    int k;
    
    scanf("%s", s);
    scanf("%d", &k);
    
    printf("%d\n", minPossibleScore(s, k));
    return 0;
}
