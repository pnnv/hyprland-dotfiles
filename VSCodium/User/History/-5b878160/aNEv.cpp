#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {	
	vector <int> v(6);
	iota(v.begin(), v.end(), 1);

	do {
		for(int i = 1; i < 6; i++)
			if(v[i] < v[i - 1] - 1)
				continue;
		for(auto i: v) cout << i << ' ';
		cout << endl;
	} while(next_permutation(v.begin(), v.end()));

	
}