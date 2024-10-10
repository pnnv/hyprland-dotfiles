#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int tt = 1;

string getMinimalString(string s) {
	deque<char> pre;
    string post;

    for (char c : s) {
        pre.push_back(c);
        post.push_back(pre.back());

        while (!pre.empty() && pre.back() == post.back()) {
            pre.pop_back(); 
        }
    }

    return post;
}

int32_t main() {

	cout << getMinimalString("xer") << endl;
}