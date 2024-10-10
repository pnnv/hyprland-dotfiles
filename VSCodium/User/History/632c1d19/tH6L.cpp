#include <bits/stdc++.h>
#include <sys/resource.h> // Include this for setrlimit

using namespace std;

typedef long long ll;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K>
using oset = tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
oset <int> st;


void solve() {
	int n; cin >> n;
	cout << st.order_of_key(n) + 1 << endl;
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
	for(int i = 0; i < primes.size() - 1; i++) {
		if(primes[i] + 2 == primes[i + 1]) {
			st.insert(primes[i]);
		}
	}

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}