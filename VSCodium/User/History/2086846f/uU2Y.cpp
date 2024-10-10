#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	string vow = "aeiou";

	int mn = 1000000;i

	for(auto v: vow) {
		int cur = 0;
		for(auto i: s) 
			cur += abs(int(i - v));
		mn = min(mn, cur);
	}

	cout << (mn == 0 ? -1 : mn) << endl;
}