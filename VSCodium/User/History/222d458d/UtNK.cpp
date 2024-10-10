#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canMinimize(const string& s, int minLen, int k) {
    int flips = 0, left = 0;
    
    // Check for both 'a' and 'b' scenarios
    for (char target : {'a', 'b'}) {
        flips = 0;
        left = 0;
        for (int right = 0; right < s.size(); ++right) {
            if (s[right] != target) {
                flips++;
            }
            while (flips > k) {
                if (s[left] != target) {
                    flips--;
                }
                left++;
            }
            if (right - left + 1 >= minLen) {
                return true;
            }
        }
    }
    return false;
}

int minimizeLongestSubstring(const string& s, int k) {
    int low = 1, high = s.size(), result = s.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMinimize(s, mid, k)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << minimizeLongestSubstring(s, k) << endl;
    return 0;
}
