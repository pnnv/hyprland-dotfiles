#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	vector <ll> dig(36);
	dig[0] = 0; dig[1] = 9; dig[2] = 9;
	for(int i = 3; i < dig.size(); i++) {
		if(i & 1) {
			ll s = 1;
			for(int j = 0; j < i; j++)
				if(j & 1)
					s += dig[j];
			dig[i] = (9LL * s);
		}  else  {
			ll s = 1;
			for(int j = 0; j < i; j++) 
				if(~j & 1)
					s += dig[j];
			dig[i] = s;
		}
	}

	for(auto i: dig) cout << i << ' ';
}