#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	for(int i = 0; i < k; i++) {
		int f = 0;
		for(int j = 0; j < n; j++) {
			if(s[j] == '1') {
				f = j; break;
			}
		}
		if(f == n && cout << 0 << endl) return;
		int a = 0;
		for(int j = f; j < n; j++) 
			if(s[j] == '0') a++;
		int f2 = -1;
		for(int j = 0; j < n; j++) {
			if(s[j] == '0') 
				f2 = j;
		}
		if(f2 == -1 && cout << 0 << endl) return;
		int b = 0;
		for(int j = 0; j < f2; j++)
		 	if(s[j] == '1') b++;
		if(a > b) {
			s[f] = '0';
		} else {
			s[f2] = '1';
		}
	}

	int cnt = 0, inv = 0;
	for(auto i: s) {
		if(i == '1') cnt++;
		else inv += cnt;
	}

	cout << inv << endl;
}


int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}