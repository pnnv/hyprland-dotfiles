#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countDivisors(int n) {
    int c = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            c += (i * i == n) ? 1 : 2;
        }
    }
    return c;
}

int32_t main() {
	string mo = "", le = "";
	
	for(char c = 'a'; c <= 'z'; c++) {
		if(countDivisors(int(c - 'a' + 1)) <= 2) le.push_back(c);
		else mo.push_back(c);
	}

	cout << mo << endl << le << endl;
}