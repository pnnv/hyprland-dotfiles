#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int getminstress(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<int> weight, int source, int destination) {
    vector<vector<pair<int, int>>> adj(graph_nodes + 1);
    for (int i = 0; i < graph_from.size(); i++) {
        adj[graph_from[i]].emplace_back(graph_to[i], weight[i]);
        adj[graph_to[i]].emplace_back(graph_from[i], weight[i]);
    }
    
    vector<int> dist(graph_nodes + 1, INT_MAX);
    dist[source] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (max(dist[u], w) < dist[v]) {
                dist[v] = max(dist[u], w);
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[destination] == INT_MAX ? -1 : dist[destination];
}


vector<int> remainingBalls(vector<int>& direction, vector<int>& strength) {
    int n = direction.size();
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (direction[i] == 1) {
            s.push(i);
        } else {
            while (!s.empty() && direction[s.top()] == 1 && strength[s.top()] < strength[i]) {
                s.pop();
            }
            if (!s.empty() && direction[s.top()] == 1 && strength[s.top()] == strength[i]) {
                s.pop();
            } else if (s.empty() || direction[s.top()] == -1) {
                s.push(i);
            }
        }
    }

    vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
}

#include <bits/stdc++.h>
using namespace std;

bool canAchieveScore(const string &s, int k, int mid) {
    int n = s.size();
    int countA = 0, countB = 0;
    
    // Check for 'a' character target
    for (int i = 0; i < n; i++) {
        if (i >= mid) {
            if (s[i - mid] == 'a') countA--;
        }
        if (s[i] == 'a') countA++;
        if (i >= mid - 1) {
            if (countA <= k) return true;
        }
    }
    
    // Check for 'b' character target
    for (int i = 0; i < n; i++) {
        if (i >= mid) {
            if (s[i - mid] == 'b') countB--;
        }
        if (s[i] == 'b') countB++;
        if (i >= mid - 1) {
            if (countB <= k) return true;
        }
    }
    
    return false;
}

int minPossibleScore(const string &s, int k) {
    int low = 1, high = s.size(), result = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAchieveScore(s, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return result;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << minPossibleScore(s, k) << endl;
    return 0;
}


// int main() {

// vector <int> d(6, 89);
// d[3] = 9090;
// 	vector <int> dir = {1, 1, 1, -1, 1, 1};

// 	auto pp = remainingBalls(dir, d);
// 	for(auto i: pp) cout << i << ' ';
// 	return 0;
// }