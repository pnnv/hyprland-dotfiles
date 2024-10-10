#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class K> using oset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector <string> g(n + 2);
  string pp(m + 2, 'X');
  g[0] = pp; g[n + 1] = pp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    string t = "X"; t += s; t.push_back('X');
    g[i + 1] = t;
  }
  oset <int> a, b;
  vector <int> p(m + 2);
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) 
      if(g[i][j] == '.' && g[i][j - 1] == 'X' && g[i - 1][j] == 'X') {
        a.insert(j - 1);
        b.insert(j); continue;
      }
        
  for(int i = 1; i < p.size(); i++) p[i] += p[i - 1];

  int q; cin >> q;
  for(; q--;) {
    int x, y; cin >> x >> y;
    if(a.empty() && cout << "YES\n") continue;
    int xx = *a.find_by_order(a.order_of_key(x));
    if(b.order_of_key(y) == 0 && cout << "YES\n") continue;
    int yy = *b.find_by_order(b.order_of_key(y) - 1);
    cout << xx << ' ' << yy << " ";
    cout << (xx < yy ? "YES\n": "NO\n");
  }
}