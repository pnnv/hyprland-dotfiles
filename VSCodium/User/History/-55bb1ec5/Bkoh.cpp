#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

using namespace std;

bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
}

void addEdges(int node, const vector<vector<int>>& tree, const vector<int>& A, vector<vector<int>>& new_tree, vector<bool>& visited) {
    for (int child : tree[node]) {
        if (!visited[child]) {
            visited[child] = true;
            addEdges(child, tree, A, new_tree, visited);
        }
        if (isPowerOfTwo(A[node] ^ A[child])) {
            new_tree[node].push_back(child);
        }
    }
}

int countPaths(int node, const vector<vector<int>>& new_tree) {
    if (new_tree[node].empty()) {
        return 1;
    }
    int paths = 0;
    for (int child : new_tree[node]) {
        paths = (paths + countPaths(child, new_tree)) % MOD;
    }
    return paths;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    vector<vector<int>> tree(N + 1);
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }

    vector<vector<int>> new_tree(N + 1);
    vector<bool> visited(N + 1, false);
    visited[1] = true;
    addEdges(1, tree, A, new_tree, visited);

    int result = countPaths(1, new_tree);
    cout << result << endl;

    return 0;
}