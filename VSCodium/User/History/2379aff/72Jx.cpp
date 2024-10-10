#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char f(char a[], int n) {
    std::sort(a, a + n);
    char x = 'a';
    for (int i = 0; i < n; i++) {
        if (a[i] == x) x++;
        else if (a[i] > x) break;
    }
    return x;
}

int32_t main() {


}