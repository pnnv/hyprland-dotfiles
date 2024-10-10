#include <stdio.h>
#include <string.h>

int canHaveLength(char* A, int n, int k, int len, char ch) {
    int cnt = 0;
    int l = 0, r = 0;

    while (r < n) {
        if (A[r] != ch)
            ++cnt;

        while (cnt > k) {
            if (A[l] != ch)
                --cnt;
            ++l;
        }

        if (r - l + 1 >= len)
            return 1;

        ++r;
    }
    return 0;
}

int minimizeMaxLength(char* A, int n, int k) {
    int left = 1, right = n;
    int result = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int possible = 0;

        if (canHaveLength(A, n, k, mid, 'a') || canHaveLength(A, n, k, mid, 'b')) {
            possible = 1;
        }

        if (possible) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n = 5, k = 2;
    char A[] = "ababa";
    printf("Minimum length = %d\n", minimizeMaxLength(A, n, k));

    n = 6, k = 4;
    char B[] = "bbbbbb";
    printf("Minimum length = %d\n", minimizeMaxLength(B, n, k));

    return 0;
}
