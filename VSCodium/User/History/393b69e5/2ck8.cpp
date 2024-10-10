#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

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
	int n; cin >> n;
	vector <int> a(n - 1), b(n - 1);
	vector <ll> w(n - 1);
	for (int i = 0; i < n - 1; i++) cin >> a[i] >> b[i] >> w[i];

	vector <int> ind(n - 1);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int x, int y) { return w[x] < w[y]; });

	mi ans = 0;
	dsu d(n);
	for(auto i: ind) {
		mi pp = 1;
		pp *= d.size(a[i] - 1);
		pp *= d.size(b[i] - 1);
		pp *= w[i];
		ans += pp;
		d.merge(a[i] - 1, b[i] - 1);
	}

	cout << int(ans) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}