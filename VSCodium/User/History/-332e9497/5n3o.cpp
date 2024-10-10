#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(int number) {
    // Negative numbers are not palindromes
    if (number < 0) return false;

    // Find the reverse of the number
    int original = number;
    int reversed = 0;

    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    // Check if the original number and the reversed number are the same
    return original == reversed;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	vector <ll> pals;
	for(int i = 0; i <= 9999999; i++) {
		if(isPalindrome(i)) pals.push_back(i);
	}
	// int n; cin >> n; cout << pals[n - 1] << endl;
	for(int i = 0; i < 50; i++) {
		cout << i + 1 << ": " << pals[i] << endl;
	}
}