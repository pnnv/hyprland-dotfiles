#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int tt = 1;

string getMinimalString(string s) {
	int n = s.size();
	string mn = s;
	for(int i = n - 2; i >= 0; i--) 
		mn[i] = min(mn[i], mn[i + 1]);

	return mn;
}

int32_t main() {

	cout << getMinimalString("zxxaxxxzzbxzxzxzzxc") << endl;
}