#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine if we can have a substring of length `len` with at most `k` changes
bool canHaveLength(string& A, int n, int k, int len, char ch) {
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
            return true;

        ++r;
    }
    return false;
}

// Function to find the minimum possible length
int minimizeMaxLength(string& A, int n, int k) {
    int left = 1, right = n;
    int result = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool possible = false;

        for (int i = 0; i < 26; ++i) {
            if (canHaveLength(A, n, k, mid, i + 'A') || canHaveLength(A, n, k, mid, i + 'a')) {
                possible = true;
                break;
            }
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

// Driver code
int main() {
    int n = 5, k = 2;
    string A = "ABABA";
    cout << "Minimum length = " << minimizeMaxLength(A, n, k) << endl;

    n = 6, k = 4;
    string B = "HHHHHH";
    cout << "Minimum length = " << minimizeMaxLength(B, n, k) << endl;

    return 0;
}
