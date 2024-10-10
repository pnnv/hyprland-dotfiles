#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int tt = 1;

string getMinimalString(string s) {
	string pre, post;
    deque<char> dq(s.begin(), s.end());

    while (!dq.empty() || !pre.empty()) {
        if (!dq.empty() && (pre.empty() || dq.front() <= pre.back())) {
            pre.push_back(dq.front());
            dq.pop_front();
        } else {
            post.push_back(pre.back());
            pre.pop_back();
        }
    }

    return post;
}

int32_t main() {

	cout << getMinimalString("xea") << endl;
}