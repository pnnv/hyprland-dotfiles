#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canFormSubstring(const string& s, int maxLen, int k, char ch) {
    int flips = 0, left = 0;
    for (int right = 0; right < s.size(); ++right) {
        if (s[right] != ch) {
            flips++;
        }
        while (flips > k) {
            if (s[left] != ch) {
                flips--;
            }
            left++;
        }
        if (right - left + 1 >= maxLen) {
            return true;
        }
    }
    return false;
}

int minimizeLongestSubstring(const string& s, int k) {
    int low = 1, high = s.size(), result = s.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFormSubstring(s, mid, k, 'a') || canFormSubstring(s, mid, k, 'b')) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
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
