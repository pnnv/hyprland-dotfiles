#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minLongestSubstring(string s, int k) {
    int n = s.length();
    int result = n;
    
    for (char ch = 'a'; ch <= 'b'; ++ch) {
        int left = 0, right = 0, maxCount = 0;
        
        while (right < n) {
            if (s[right] == ch) {
                maxCount++;
            }
            
            if (right - left + 1 - maxCount > k) {
                if (s[left] == ch) {
                    maxCount--;
                }
                left++;
            }
            
            result = min(result, right - left + 1);
            right++;
        }
    }
    
    return result;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    cout << minLongestSubstring(s, k) << endl;
    
    return 0;
}
