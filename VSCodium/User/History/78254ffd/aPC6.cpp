#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5, M = 2 * N + 5;
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
set <ll> p;

void Gen() {
  for (int i = 2; i < N; ++i)
    if (vis[i])
      p.insert(i);
}


void snu() {
  ll n; cin >> n;
  if(n < 38 && cout << "No\n") return;
  n -= 4;
  for(auto i: p) {
    if(n - (i * i) != (i * i)) {
      ll sq = sqrtl(n - (i * i));
      if(ll sq = sqrtl(n - (i * i)); sq * sq == n - (i * i)) {
        if(p.count(n - (i * i)) && cout << "Yes\n") return;
      }
    } 
  }
  cout << "No\n";
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve(); Gen();
  int t; cin >> t;
  while(t--) snu();
}