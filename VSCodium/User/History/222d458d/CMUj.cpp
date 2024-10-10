#include <bits/stdc++.h>
using namespace std;

vector<int> remainingBalls(vector<int>& direction, vector<int>& strength) {
    int n = direction.size();
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (direction[i] == 1) {
            // Moving right, simply push to stack
            s.push(i);
        } else {
            // Moving left, resolve collisions
            while (!s.empty() && direction[s.top()] == 1 && strength[s.top()] < strength[i]) {
                s.pop();
            }
            if (!s.empty() && direction[s.top()] == 1 && strength[s.top()] == strength[i]) {
                // Both have the same strength, both are destroyed
                s.pop();
            } else if (s.empty() || direction[s.top()] == -1) {
                // No collision, this ball survives
                s.push(i);
            }
        }
    }

    // Convert stack to result vector
    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    
    // The remaining balls will be in reverse order in the stack
    reverse(result.begin(), result.end());
    return result;
}

int main() {

vector <int> d(8, 89);
	vector <int> dir = {-1, -1, -1, 1, 1, 1, 1, 1};

	auto pp = remainingBalls(dir, d);
	for(auto i: pp) cout << i << ' ';
	return 0;
}