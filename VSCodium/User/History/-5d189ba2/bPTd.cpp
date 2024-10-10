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

namespace atc {
namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
  int x = 0;
  while ((1U << x) < (unsigned int)(n))
	x++;
  return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}

} 
} 

namespace atc {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
  segtree() : segtree(0) {}
  segtree(int n) : segtree(std::vector<S>(n, e())) {}
  segtree(const std::vector<S> &v) : _n(int(v.size())) {
	log = internal::ceil_pow2(_n);
	size = 1 << log;
	d = std::vector<S>(2 * size, e());
	for (int i = 0; i < _n; i++) d[size + i] = v[i];
	for (int i = size - 1; i >= 1; i--) update(i);
  }

  void set(int p, S x) {
	assert(0 <= p && p < _n); p += size;
	d[p] = x;
	for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
	assert(0 <= p && p < _n);
	return d[p + size];
  }

  S prod(int l, int r) {
	assert(0 <= l && l <= r && r <= _n);
	S sml = e(), smr = e();
	l += size; r += size;

	while (l < r) {
	  if (l & 1) sml = op(sml, d[l++]);
	  if (r & 1) smr = op(d[--r], smr);
	  l >>= 1;
	  r >>= 1;
	}
	return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  template <bool (*f)(S)> int max_right(int l) {
	return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) {
	assert(0 <= l && l <= _n);
	assert(f(e()));
	if (l == _n) return _n;
	l += size;
	S sm = e();
	do {
	  while (l % 2 == 0) l >>= 1;
	  if (!f(op(sm, d[l]))) {
		while (l < size) {
		  l = (2 * l);
		  if (f(op(sm, d[l]))) {
			sm = op(sm, d[l]); l++;
		  }
		}
		return l - size;
	  }
	  sm = op(sm, d[l]); l++;
	} while ((l & -l) != l);
	return _n;
  }

  template <bool (*f)(S)> int min_left(int r) {
	return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) {
	assert(0 <= r && r <= _n);
	assert(f(e()));
	if (r == 0) return 0;
	r += size;
	S sm = e();
	do {
	  r--;
	  while (r > 1 && (r % 2)) r >>= 1;
	  if (!f(op(d[r], sm))) {
		while (r < size) { r = (2 * r + 1);
		  if (f(op(d[r], sm))) {
			sm = op(d[r], sm); r--;
		  }
		}
		return r + 1 - size;
	  }
	  sm = op(d[r], sm);
	} while ((r & -r) != r);
	return 0;
  }

private:
  int _n, size, log; std::vector<S> d;
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
}
using namespace atc;

mi op(mi a, mi b)  { return (a * b); }
mi e() { return mi(1); }



// class Solution {
//   public:
    vector<int> treeQueries(int N, vector<int> &A, vector<vector<int>> &G, int Q, vector<vector<int>> &queries) {
		vector <int> fin;
		vector <mi> a;
		for(auto i: A) a.push_back(mi(i));
		segtree <mi, op, e> st(a); 
		vector <vector <int>> t(N);
		
		for(auto edge: G) {
			t[edge[0]].push_back(edge[1]);	
			t[edge[1]].push_back(edge[0]);	
		}
		vector <int> sz(N);

		function <int(int, int)> dfs = [&](int p, int c) {
			int cur = 1;
			for(auto v: t[c])
				if(v != p) cur += dfs(c, v);
			return sz[c] = cur;
		}; dfs(-1, 0);

		for(auto i: sz) cout << i << ' ';
		cout << endl;

		for(auto i: queries) {
			if(i[0] == 1) {
				st.set(i[1], mi(i[2]));
				fin.push_back(-1);
			} else  {
				fin.push_back(int(st.prod(i[1], i[1] + sz[i[1]])));
			}

			cout << "lmao: ";
			for(int j = 0; j < N; j++) {
				cout << int(st.get(j)) << ' ';
			}
			cout << endl;
		}

		return fin;
    }
// };

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	vector <int> a(n);
	for(auto &i: a) cin >> i;
	vector <vector <int>> g(n - 1, vector <int> (2));
	for (int i = 0; i < n - 1; i++) cin >> g[i][0] >> g[i][1];

	int q; cin >> q;
	vector <vector <int>> qq(q, vector <int> (3));
	for(int i = 0; i < q; i++) cin >> qq[i][0] >> qq[i][1] >> qq[i][2];

	auto pp = treeQueries(n, a, g, q, qq);	
	
	for(auto i: pp) cout << i << ' ';
	cout << endl;
}