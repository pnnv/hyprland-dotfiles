#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int n, t, a; cin >> n >> t >> a;
	if(a > (n / 2) || t > (n / 2)) cout << "Yes\n";
	else cout << "No\n";
}