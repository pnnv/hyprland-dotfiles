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

string penis(ll n) {
	// ll n; cin >> n;
	if(n == 1 && cout << 0 << endl) return "0";
	ll dig = 0; n--;
	
	for(int i = 1; i < 69; i++) {
		ll pp = (9LL * (ll(pow(10LL, ((i - 1LL) / 2LL)))));
		if(pp < n) n -= pp;
		else {
			n += (pow(10, ((i + 1) / 2) - 1) - 1);
			dig = i; break;
		}
	}
	string st = to_string(n);
	string p = st;
	if(dig & 1) p.pop_back();
	reverse(p.begin(), p.end());
	st += p;
	return st;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);

	int a, b; cin >> a >> b;
	for(int i = a; i <= b; i++) penis(i);
	
	vector <ll> pals;
	for(int i = 0; i <= 9999999; i++) {
		if(isPalindrome(i)) pals.push_back(i);
	}

	for(int i = 1; i <= pals.size(); i++) {
		string pp = to_string(pals[i - 1]);
		string pipi = penis(i);
		// if(pp != pipi) {
			cout << i << ": " << pipi << ' ' << pp << endl;
		// }
	}
}