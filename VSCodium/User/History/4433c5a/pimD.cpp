#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void snu() {
	int n; cin >> n;
	vector <ld> a(n), b(n);
	for(auto &i: a) cin >> i; 
	for(auto &i: b) cin >> i; 

	vector <int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int x, int y) { return a[x] < a[y]; });

	stack <ld> s;

	for (int i: ind) {
		while(!s.empty() && s.top() > a[i] / b[i]) s.pop();
		s.push(a[i] / b[i]);
	}

	cout << s.size() << endl;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--) snu();
}