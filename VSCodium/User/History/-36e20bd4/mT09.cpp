#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	int n; cin >> n;
	string a, b; cin >> a >> b;
	ll cnt = 0;
	for(int i = 1; i < n - 1; i++) 
		if(a[i] == '.' && b[i + 1] == 'x' && b[i - 1] == 'x') cnt++;	
	swap(a, b);

	for(int i = 1; i < n - 1; i++) 
		if(a[i] == '.' && b[i + 1] == 'x' && b[i - 1] == 'x') cnt++;

	cout << cnt << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}