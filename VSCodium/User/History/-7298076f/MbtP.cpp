#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100005
#define MAX_M 100000

typedef long long ll;

// Utility function to find the next number in the range that is not in the array
int find_missing(int *arr, int size, int max) {
    bool present[MAX_N] = { false };
    for (int i = 0; i < size; i++) {
        if (arr[i] < max) {
            present[arr[i]] = true;
        }
    }
    for (int i = 0; i <= max + 2; i++) {
        if (!present[i]) {
            return i;
        }
    }
    return -1;
}

// Recursive function to compute the maximum number of intervals
void compute_max(ll *mx, int *v[], bool *taken, int *fin, int c, int m) {
    if (v[c][0] != -1 && v[c][1] != -1) {
        *mx = c;
    }
    if (c <= m && !taken[c]) {
        *fin -= c;
        *fin += *mx;
        taken[c] = true;
    }
    for (int j = 0; v[c][j] != -1; j++) {
        int u = v[c][j];
        if (!taken[u]) {
            compute_max(mx, v, taken, fin, u, m);
        }
    }
}

void snu() {
    ll n, m, fin;
    scanf("%lld %lld", &n, &m);
    fin = (m * (m + 1LL)) / 2LL;

    int v[MAX_N][MAX_N];
    bool taken[MAX_N] = { false };
    ll mx = 0;

    // Initialize the v array
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            v[i][j] = -1;
        }
    }

    for (int _ = 0; _ < n; _++) {
        int l;
        scanf("%d", &l);
        int arr[l];
        for (int j = 0; j < l; j++) {
            scanf("%d", &arr[j]);
        }
        int a = find_missing(arr, l, MAX_N);
        int b = find_missing(arr, l, a);
        if (b != -1) {
            for (int i = 0; i < MAX_N; i++) {
                if (v[b][i] == -1) {
                    v[b][i] = a;
                    break;
                }
            }
        }
    }

    for (int cur = MAX_N - 1; cur >= 0; cur--) {
        if (taken[cur]) continue;
        mx = cur;
        compute_max(&mx, v, taken, &fin, cur, m);
        if (mx != 0) break;
    }
    for (int j = 0; j < mx; j++) {
        if (!taken[j]) {
            fin -= j;
            fin += mx;
        }
    }

    printf("%lld\n", fin);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        snu();
    }
    return 0;
}
