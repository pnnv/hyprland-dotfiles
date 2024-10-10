#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, op = 0; cin >> n;
	vector <int> v(n), ti;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if(v[i] > 4) v[i] = 0;
		else if(v[i] > 2) v[i] = 4;
		else if(v[i] > 0) ti.push_back(i);
		else op--; 
	}
	op += n;
	if((ti.empty() || ti.size() == 1) && cout << op << endl) return;
	int p = 0;
	while(p < ti.size() - 1) {
		bool chinchin = true;
		for(int i = ti[p] + 1; i < ti[p + 1]; i++) {
			if(v[i] != 4) { chinchin = false; break; }
		}
		if(chinchin && (ti[p + 1] - ti[p] - 1) % 2 == 0) {
			op--; p += 2;
		} else p++;
	}
	cout << op << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}