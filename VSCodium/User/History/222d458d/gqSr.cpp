#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine if we can have a substring of length `len` with at most `k` changes
bool canHaveLength(string& A, int n, int k, int len, char ch) {
    int cnt = 1;
	
}

// Function to find the minimum possible length
int minimizeMaxLength(string& a, int n, int k) {

	auto isp = [&](int x) {
		int cur = 1, f = 0;
		string s = a;
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i - 1]) {
				cur++;
				if(cur > x) {
					if(s[i] == 'a') s[i] = 'b';
					else if(s[i] == 'b') s[i] = 'a';
					cur = 1; f++;
				}
			} else {
				cur = 1;
			}
		}
		return f <= k;
	};
	int left = 1, right = a.size(), result = a.size();
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool possible = false;

        possible = isp(mid);

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
