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

	auto chinchin = [&](int i) {
		ll a  = pals[i - 1];
		int n = i;
		ll dig = 0; n--;
		for(int i = 1; i < 69; i++) {
			ll pp = (9LL * (ll(pow(10LL, ((i - 1LL) / 2LL)))));
			if(pp <= n) n -= pp;
			else {
				dig = i; break;
				n += (pow(10, ((i + 1) / 2) - 1) - 1);
			}
		}
		// if(n == 0) {
		// 	cout << 1;
		// 	for(int i = 0; i < dig - 2; i++) cout << 0;
		// 	cout << 1 << endl;
		// 	return 0;
		// }
		string st = to_string(n);
		string p = st;
		if(dig & 1) p.pop_back();
		reverse(p.begin(), p.end());
		st += p;
		// ll b = stoll(st);

		 cout << i << " - " << st << ": " << a << endl;
		return;
	};

	for(int i = 1; i < 1000; i++) {
		chinchin(i);
	}
}