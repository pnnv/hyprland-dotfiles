#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {	
	vector <int> v(8);
	iota(v.begin(), v.end(), 1);
	int cnt = 0;
	do {
		bool pp = false;
		for(int i = 1; i < 8; i++)
			if(v[i] < v[i - 1] - 1)
				pp = true;
		if(pp) continue;
		cout << ++cnt << ": ";
		for(auto i: v) cout << i << ' ';
		cout << endl; 
	} while(next_permutation(v.begin(), v.end()));
}

/*

1: 1 2 3 4 5 6 
2: 1 2 3 4 6 5 
3: 1 2 3 5 4 6 
4: 1 2 3 6 5 4 
5: 1 2 4 3 5 6 
6: 1 2 4 3 6 5 
7: 1 2 5 4 3 6 
8: 1 2 6 5 4 3 
9: 1 3 2 4 5 6 
10: 1 3 2 4 6 5 
11: 1 3 2 5 4 6 
12: 1 3 2 6 5 4 
13: 1 4 3 2 5 6 
14: 1 4 3 2 6 5 
15: 1 5 4 3 2 6 
16: 1 6 5 4 3 2 
17: 2 1 3 4 5 6 
18: 2 1 3 4 6 5 
19: 2 1 3 5 4 6 
20: 2 1 3 6 5 4 
21: 2 1 4 3 5 6 
22: 2 1 4 3 6 5 
23: 2 1 5 4 3 6 
24: 2 1 6 5 4 3 
25: 3 2 1 4 5 6 
26: 3 2 1 4 6 5 
27: 3 2 1 5 4 6 
28: 3 2 1 6 5 4 
29: 4 3 2 1 5 6 
30: 4 3 2 1 6 5 
31: 5 4 3 2 1 6 
32: 6 5 4 3 2 1 

*/