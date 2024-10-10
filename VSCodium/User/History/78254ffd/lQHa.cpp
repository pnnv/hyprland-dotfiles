#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5, M = 2 * N + 5;

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
set <int> p;

void Gen() {
  for (int i = 2; i < N; ++i)
    if (vis[i])
      primes.emplace_back(i);
}

long long int Sqrt(long long int x) {
  if (x == 0 || x == 1)
      return x;

  long long int s = 1, e = x, ans = 0;
  while (s <= e) {
    long long int m = (s + e) / 2;
    if (m * m == x) return m;
    if (m * m < x) {
      s = m + 1; ans = m;
    } else {
      e = m - 1;
    }
  }
  return ans;
}


void snu() {
  ll n; cin >> n;
  if(n < 38 && cout << "No\n") return;
  n -= 4;

  for(int i = 1; primes[i] * primes[i] <= n; i++) {
    ll req = n -  primes[i] * primes[i];
    if(req <= 0) continue;
    ll sq = Sqrt(req);
    if(sq * sq == req && sq != primes[i]) {
      if(p.find(sq) != p.end()) {
        cout << "Yes\n"; return;
      }
    }
  }

  cout << "No\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve(); Gen();
  for(auto i: primes) p.insert(i);
  int t; cin >> t;
  while(t--) snu();
}