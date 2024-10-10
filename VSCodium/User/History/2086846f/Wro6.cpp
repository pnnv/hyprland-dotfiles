#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	set <char> vow; 
	vow.insert('a');
	vow.insert('e');
	vow.insert('i');
	vow.insert('o');
	vow.insert('u');

	int mn = 69696969;

	for(auto c: vow) {
		int cur = 0;
		for(auto i: s) {
			if(vow.find(i) != vow.end()) cur += int(abs(i - c));
			else cur += 10;
		}
		cout << cur << endl;
		mn = min(mn, cur);
	}
	cout << (mn == 0 ? -1 : mn) << endl; 
}