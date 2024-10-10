#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> dp(N + 1, LLONG_MAX);
    dp[0] = 0; // Base case: no cost to start
    
    for (int i = 0; i < N; ++i) {
        long long sum = 0;
        for (int k = 1; k <= 3 && i + k <= N; ++k) {
            sum += A[i + k - 1];
            dp[i + k] = min(dp[i + k], dp[i] + sum);
        }
    }
    
    cout << dp[N] << endl;
    return 0;
}