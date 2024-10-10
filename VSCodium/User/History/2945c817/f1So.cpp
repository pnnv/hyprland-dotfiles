#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;

struct compare {
  bool operator() (pair <int, int> a, pair <int, int> b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second > b.second;
  }
};

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  
  int n; cin >> n;
  queue <pair <int, int>> q;
  priority_queue<pair <int, int> , vector <pair <int, int>>, compare> pq;
  set <int> rem;
  int pp = 1;

  while(n--) {
    int x; cin >> x;
    if(x == 1) {
      int m; cin >> m;
      q.push({pp, m});
      pq.push({m, pp});
      pp++;
    } else if(x == 2) {
      while(rem.count(q.front().first)) q.pop();
      cout << q.front().first << ' ';
      rem.insert(q.front().first); q.pop();
    } else {
      while(rem.count(pq.top().second)) pq.pop();
      cout << pq.top().second << ' ';
      rem.insert(pq.top().second); pq.pop();
    }
  }
}