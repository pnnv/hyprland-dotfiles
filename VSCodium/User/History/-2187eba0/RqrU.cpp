#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 2 * N + 5;

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

typedef long long ll;

void snu() {
	int n; cin >> n;
	cout << "penis";
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	Sieve(); Gen();

	for(int i = 0; i < 50; i++) {
		cout << bitset <10> (primes[i]) << endl;
	}

	int t; cin >> t;
	while(t--) snu();
}