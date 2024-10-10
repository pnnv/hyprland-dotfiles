#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <int> dx = {1, 0, -1, 0};
vector <int> dy = {0, 1, 0, -1};

struct dsu {
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y]; parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n); assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i); group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

private:
  int _n;
  std::vector<int> parent_or_size;
};

void snu() {
  int n, m; cin >> n >> m;
  vector <string> g;
  string pp(m + 2, '.'); g.emplace_back(pp);
  for (int i = 0; i < n; i++) {
    string p = ".";
    string s; cin >> s; p += s; p.push_back('.');
    g.emplace_back(p);
  }
  g.emplace_back(pp);
  auto sn = [&](ll i, ll j) { return (i * (m + 2LL)) + j;};
  dsu d((n + 2LL) * (m + 2LL));
  map <ll, ll> ms;

  ll sz = 0; ll par;
  vector <vector <bool>> vis(n + 2, vector <bool> (m + 2, false));
  function <void(int, int)> fill = [&](int x, int y) {
    if(g[x][y] == '.') return;
    else if(vis[x][y]) return;
    vis[x][y] = true; sz++;
    d.merge(sn(x, y), par);
    for(int i = 0; i < 4; i++)
      fill(x + dx[i], y + dy[i]);
  };

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(!vis[i][j] && g[i][j] == '#') {
        sz = 0; par = sn(i, j);
        fill(i, j);
        ms[par] = sz;
      }
    }
  }

  ll mx = 0;

  for(int i = 1; i <= n; i++) {
    ll cnt = 0;
    set <int> prs;
    for(int j = 1; j <= m; j++) {
      for(int k = -1; k <= 1; k++) {
        ll cs = sn(i, j + k); 
        if(g[i][j + k] == '#') {
          if(prs.find(cs) == prs.end()) {
            cnt += ms[d.leader(cs)];
            prs.insert(cs);
          }
        }
      }
      if(g[i][j] == '.') cnt++;
    }
    mx = max(mx, cnt);
  }

  for(int i = 1; i <= m; i++) {
    ll cnt = 0;
    set <int> prs;
    for(int j = 1; j <= n; j++) {
      for(int k = -1; k <= 1; k++) {
        ll cs = sn(i, j + k); 
        if(g[j + k][i] == '#') {
          if(prs.find(cs) == prs.end()) {
            cnt += ms[d.leader(cs)];
            prs.insert(cs);
          }
        }
      }
      if(g[j][i] == '.') cnt++;
    }
    mx = max(mx, cnt);
  }

  cout << mx << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}