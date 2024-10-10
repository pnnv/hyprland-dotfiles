#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string s; cin >> s;
	string a = "", b = "";
	
	auto ck = [&]() {
		for(int i = 1; i < a.size(); i++) if(a[i] > a[i - 1]) return false;
		for(int i = 1; i < b.size(); i++) if(b[i] > b[i - 1]) return false;
		return true;
	};

	for(int i = -1; i <= 9; i++) {
		vector <int> pp(n);
		for(int j = 0; j < n; j++) {
			
		}
	}
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}