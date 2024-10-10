#include <bits/stdc++.h>
#include <sys/resource.h> // Include this for setrlimit

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e7 + 5, M = 2 * N + 5;

bool vis[N], ans;

void Sieve() {
  memset(vis, true, sizeof(vis));

  vis[0] = vis[1] = false;
  for (int i = 4; i < N; i += 2)
	vis[i] = false;
  for (int i = 3; i < N / i; i += 2) {
	if (!vis[i])
	  continue;
	for (int j = i * i; j < N; j += i + i)
	  vis[j] = false;
  }
}

int in[N], vid;
vector<int> primes;

void Gen() {
  for (int i = 2; i < N; ++i)
	if (vis[i])
	  primes.emplace_back(i);
}

void solve() {
    cout << primes.size() << endl;
}

int main() {
    const rlim_t kStackSize = 1024 * 1024 * 1024; 
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0) {
                cerr << "setrlimit returned result = " << result << endl;
            }
        }
    }

	Sieve(); Gen();

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}