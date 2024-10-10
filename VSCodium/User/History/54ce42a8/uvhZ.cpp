#include <bits/stdc++.h>
using namespace std; 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int diag ;
        int sum =n;
        if(k==0)
        diag = 0;
        else if (n >= k)
            diag = 1;
        else {
            for (int i = 1; i < n; i++) {
                sum += + 2 * (n - i);
                if (sum > k) {
                    diag = 2 *i + 1;
                    break;
                }
            }
        }
        
        cout << diag << endl;
    }
}