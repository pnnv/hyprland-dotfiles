#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	int n, N; cin >> n >> N;
	set <int> s;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		s.insert(x);
	}

	int cnt = 0;
	
	if(s.count(1)) {
		cout << N << endl;
		return 0;
	}

	for(int i = 1; i <= N; i++) {
		if(s.count(i)) {
			cnt++; continue;
		}

		bool x = false;
		for(int j = 2; j * j <= i; j++) {
			if(j % i == 0) {
				if(s.count(j)) x = true;
				else if(s.count(j / i)) x = true;
			}
		}
		if(x) cnt++;
	}

	cout << cnt << endl;
}