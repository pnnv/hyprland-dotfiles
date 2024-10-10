#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	vector <int> v(4);
	for(auto &i: v) cin >> i;
	vector <int> a = {v[0], v[1]}, b{v[2], v[3]};
	vector <int> a2 = a; swap(a2[0], a2[1]);
	vector <int> b2 = a; swap(b2[0], b2[1]);
	vector <vector <int>> p1, p2;
	p1.push_back(a); p1.push_back(a2);
	p2.push_back(b); p2.push_back(b2);

	int tt = 0;
	for(int i = 0; i < 2; i++) {
		int w = 0, l = 0;
		for(int j = 0; j < 2; j++) {

			if(p1[i][0] > p2[j][0]) w++;
			else if(p1[i][0] < p2[j][0]) l++;

			if(p1[i][1] > p2[j][1]) w++;
			else if(p1[i][1] < p2[j][1]) l++;
		}
		if(w > l) tt++;
	}

	cout << tt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}