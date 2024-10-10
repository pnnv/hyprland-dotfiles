#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {
	int n; cin >> n;
	vector <ld> a(n), b(n);
	for(int i = 0; i < n; i++) 
		cin >> a[i] >> b[i];

	ld lo = 0, hi = 0;
	for (int i = 0; i < n; i++) {
		hi = max(hi, ld(i + ld(1)) / b[i]);
	}
	for (int i = 0; i < n; i++) {
		if((ld(i + ld(1)) / hi) < a[i]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << hi << endl;
}


void main_() {
    int t; cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%esp, (%0)\n"
        "mov %0, %%esp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%esp\n" : : "r"(send));
    free(stack);
}
int main() {
    run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
    return 0;
}
