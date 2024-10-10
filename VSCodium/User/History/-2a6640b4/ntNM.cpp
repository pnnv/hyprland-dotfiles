#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 49, M = 2 * N + 5;

bool vis[N], ans;

void Sieve() {
  memset(vis, true, sizeof(vis));
  vis[0] = vis[1] = false;
  for (int i = 4; i < N; i += 2) vis[i] = false;
  for (int i = 3; i < N / i; i += 2) {
	if (!vis[i]) continue;
	for (int j = i * i; j < N; j += i + i) vis[j] = false;
  }
}

int in[N], vid;
vector<int> primes;

void Gen() {
  for (int i = 2; i < N; ++i)
	if (vis[i]) primes.emplace_back(i);
}

void snu() {
	int n; cin >> n;
	vector <ll> v(n);
	map <ll, set <int>> fx;
	for(auto &i: v) cin >> i;

	auto px = [&](ll c, ll d) {
		ll x = c;
		for(int i = 0; i < primes.size(); i++) 
			if(c % primes[i] == 0) 
				fx[primes[i]].insert(((primes[i] - (d % primes[i]))) % primes[i]);
	};

	for (int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(v[i] == v[j] && cout << "NO\n") return;
			ll c = abs(v[i] - v[j]);
			px(c, v[i]);
		}
	}

	for(auto &[a, b]: fx)
		if(a == b.size() && cout << "NO\n") return;

	cout << "YES\n";	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Sieve(); Gen();
	int t; cin >> t;
	while(t--) snu();
}