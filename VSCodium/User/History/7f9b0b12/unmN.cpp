#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int smol(vector <int> v, int k) {
	int n = v.size();
	int mn = 10000;

	for(int i = 0; i < n; i++) {
		vector <int> pos(k); pos[0] = 1;
		for(int j = i; j < n; j++) {
			for(int p = k; p >= v[j]; p--) {
				pos[p] += pos[p - v[j]];
			}
			if(pos[k] > 0) {
				mn = min(mn, j - i + 1);
				break;
			}
		}
	}

	return (mn == 10000 ? -1: mn);
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
}