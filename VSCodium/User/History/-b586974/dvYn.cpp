#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
	int n; cin >> n;
	vector <ld> a(n), b(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i] >> b[i];

	ld lo = 0, hi = 0;
	for (int i = 0; i < n; i++) {
		hi = max(hi, ld(i + ld(1)) / b[i]);
	}
	for (int i = 0; i < n; i++) {
		if((ld(i + ld(1)) / hi) < a[i]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << hi << endl;
}


int main() {
    int t; cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
