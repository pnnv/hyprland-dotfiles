#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	map <int, int> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; m[x]++;
	}
	int tot = 0;
	vector <int> f;
	for(auto i: m) {
		f.push_back(i.second);
		tot += i.second;
	}
	sort(f.begin(), f.end());
	int pp = f.size();
	int mx = 0; 
	for(int i = 0; i < pp; i++) 
		mx = max(mx, tot - (tot % (pp - i)));
	cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}