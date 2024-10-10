#include <bits/stdc++.h>
using namespace std;

#define int long long

long minOperations(long n) {
	long ans = 0;
	long long sz = 0, tmp = n;
	while(tmp > 0) {
		tmp >>= 1; sz++;
	}

	for(int i = 0; i <= sz; i++) {
		ans = (1LL << (i + 1)) - 1 - ans;
	}

	return ans;
}



int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	cout << sizeof(long long) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(int32_t) << endl;
	cout << sizeof(int64_t) << endl;

	int n; cin >> n;
	int fin = 0;
	

	cout << bitset <10>(n) << endl;

	for(int i = 0;  i <= 32; i++) {
		if(n & (1LL << i)) {
			fin = (1LL << (i + 1)) - 1 - fin;
		}
	}
	cout << minOperations(n) << ": ";
	cout << fin << endl;
}