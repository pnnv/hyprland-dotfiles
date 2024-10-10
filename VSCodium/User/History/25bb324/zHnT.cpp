
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

bool canReachCorner(int x, int y, vector<vector<int>>& c) {
	int n = c.size();
	dsu d(n + 4);

	for (int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			int dist_squared =
			    ((c[i][0] - c[j][0]) * (c[i][0] - c[j][0]) + (c[i][1] - c[j][1]) * (c[i][1] - c[j][1]));
			if(dist_squared <= ((c[i][2] - c[j][2]) * (c[i][2] - c[j][2]))) d.merge(i, j);
		}
		if(c[i][0] - c[i][2] <= 0) d.merge(i, n);
		if(c[i][1] + c[i][2] >= y) d.merge(i, n + 1);
		if(c[i][0] + c[i][2] >= x) d.merge(i, n + 2);
		if(c[i][1] - c[i][2] <= 0) d.merge(i, n + 3);
	}

	return (d.same(n, n + 3) || d.same(n, n + 2) || d.same(n + 3, n + 1) || d.same(n + 2, n + 1)); 
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	return 0;
}