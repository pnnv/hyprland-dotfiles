#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	int h, w; cin >> h >> w;
	int a, b; cin >> a >> b; a--; b--;
	vector <string> g(h);
	for(auto &i: g) cin >> i;
	string x; cin >> x;
	int n = x.size();
	int fa, fb;
	function <void (int, int, int)> move = [&](int i, int a, int b) {
		if(i == n) {
			fa = a, fb = b; return;
		}
		int da = a, db = b;
		if(x[i] == 'U') da--;
		else if(x[i] == 'D') da++;
		else if(x[i] == 'L') db--;
		else db++;
		if(da >= 0 && db >= 0 && da < h && db < w && g[da][db] != '#') move(i + 1, da, db);
		else move(i + 1, a, b);
	}; move(0, a, b);

	cout << fa + 1 << ' ' << fb + 1 << endl;
}