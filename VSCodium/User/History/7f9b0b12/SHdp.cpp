#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, N;
    cin >> n >> N;
    set<int> s;
	
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    if (s.find(1) != s.end()) {
        cout << N << endl;
        return 0;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (s.find(i) != s.end()) {
            cnt++;
            continue;
        }
        
        bool pp = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                if (s.find(j) != s.end() || s.find(i / j) != s.end()) {
                    pp = true;
                    break;
                }
            }
        }
        if (pp) cnt++;
    }

    cout << cnt << endl;
    return 0;
}
