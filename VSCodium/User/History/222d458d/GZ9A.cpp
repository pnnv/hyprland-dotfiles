#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int minimizeLongestSubstring(string s, int k) {
    int n = s.length();
    vector<int> countA(n + 1, 0), countB(n + 1, 0);

    // Precompute number of flips needed to make substrings of 'a' and 'b'
    for (int i = 0; i < n; ++i) {
        countA[i + 1] = countA[i] + (s[i] != 'a');
        countB[i + 1] = countB[i] + (s[i] != 'b');
    }

    int minLength = n;

    // Function to find maximum length of substring with all 'targetChar' by using at most k flips
    auto maxLengthWithFlips = [&](const vector<int>& count) {
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            int left = 0, right = i;
            while (right < n && count[right + 1] - count[left] <= k) {
                maxLength = max(maxLength, right - left + 1);
                right++;
            }
            if (right >= n) break;
            left++;
        }
        return maxLength;
    };

    // Compute the maximum lengths for both characters
    int maxLengthForA = maxLengthWithFlips(countA);
    int maxLengthForB = maxLengthWithFlips(countB);

    // The minimum length of the longest contiguous substring with the same character
    minLength = min(maxLengthForA, maxLengthForB);

    return minLength;
}

int main() {
    string s;
    int k;
    cin >> s >> k;

    cout << minimizeLongestSubstring(s, k) << endl;

    return 0;
}
