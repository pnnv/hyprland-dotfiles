#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

bool w(int x) {
	if(x <= 3) return true;
	else return (!(w(x - 1) && w(x - 2) && w(x - 3)));
}


int32_t main() {
	// cin >> n;
	n = 9;
	cout  << (w(n) ? "first" : "second") << endl;
}