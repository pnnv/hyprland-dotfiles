#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int tt = 1;

string getMinimalString(string s) {
	// int n = s.size();
	// string mn = s;
	// for(int i = n - 2; i >= 0; i--) 
	// 	mn[i] = min(mn[i], mn[i + 1]);

	// string fin = "",  pre = "";

	// for(int i = 0; i < n; i++) {
	// 	while(!pre.empty() && pre.back() < mn[i]) {
	// 		fin.push_back(pre.back());
	// 		pre.pop_back();
	// 	}
	// 	pre.push_back(s[i]);
	// }
	// while(!pre.empty()) {
	// 	fin.push_back(pre.back());
	// 	pre.pop_back();
	// }
	
	// return fin;

    string s1 = s;
    sort(s1.begin(), s1.end());
    
    string ans = "", pre = "";
    int j = 0;
    for( int i = 0; i < s.size(); i++ )
    {
       if( s[i] == s1[j] ) ans += s1[j++];
       else pre.push_back( s[i] );
    }

    reverse(pre.begin(), pre.end());
    ans += pre;

	return ans;
}

int32_t main() {

	cout << getMinimalString("xaxxaxax") << endl;
}