#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canAchieveScore(const string& s, int k, int targetScore) {
    int flips = 0;
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (i == 0 || s[i] == s[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if (count == targetScore) {
            flips++;
            count = 0;
        }
    }
    return flips <= k;
}

int minScoreBinarySearch(const string& s, int k) {
    int left = 1;
    int right = s.length();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canAchieveScore(s, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    string s = "aaaaa";
    int k = 1;
    cout << "Minimum score: " << minScoreBinarySearch(s, k) << endl;
    return 0;
}