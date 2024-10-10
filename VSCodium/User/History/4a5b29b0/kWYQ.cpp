#include <bits/stdc++.h>
using namespace std;

#define int long long

long minOperations(long n) {
	long ans = 0;
	long long sz = 0, tmp = n;
	while(tmp > 0) {
		tmp >>= 1; sz++;
	}

	for(int i = 0; i < sz; i++) {
		if(n & (1 << i)) {
			ans = (1LL << (i + 1)) - 1 - ans;
		}
	}

	return ans;
}

long rearrangeStudents(vector <int> a, vector <int> b) {
	map <int, int> fa, fb;
	for(auto i: a) fa[i]++;
	for(auto i: b) fb[i]++;

	vector <long> sa, sb;

	for(auto &[i, f]: fa) {
		if(f > fb[i]) {
			int ext = f - fb[i];
			if(ext & 1) return -1;
			for(int j = 0; j < (ext >> 1); j++) {
				sa.push_back(i);
			}
		}
	}

	for(auto &[i, f]: fb) {
		if(f > fa[i]) {
			int ext = f - fa[i];
			if(ext & 1) return -1;
			for(int j = 0; j < (ext >> 1); j++) {
				sb.push_back(i);
			}
		}
	}
	
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end(), greater<>());

	long ans = 0;

	for(int i = 0; i < sa.size(); i++) {
		ans += min(sa[i], sb[i]);
	}

	return ans;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	// int n; cin >> n;
	// int fin = 0;
	

	// cout << bitset <10>(n) << endl;

	// for(int i = 0;  i <= 32; i++) {
	// 	if(n & (1LL << i)) {
	// 		fin = (1LL << (i + 1)) - 1 - fin;
	// 	}
	// }
	// cout << minOperations(n) << ": ";
	// cout << fin << endl;

	vector <int> a = {4, 1, 2, 2}, b = {2, 4, 1, 2};
	cout  << rearrangeStudents(a, b) << endl;

}