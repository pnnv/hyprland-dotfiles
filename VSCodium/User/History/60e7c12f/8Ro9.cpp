#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, x, y;
    cin >> d >> x >> y;
    int count = 0;
    int mauka = d;
	int ans = -1;
    while (y > 0) {
      count++;
      y--;
	  if(100 * y <= x * (100 - mauka)) {
		ans = count;
		break;
	  }
    //   // x=x-(x*d*mauka)/100;

    //   if (100 * y >= (x * (100 - mauka)))
    //     break;
    //   mauka++;
    //   if (d * mauka >= 100 && x > y) {
    //     cout << -1 << endl;
    //     break;
    //   }
    }

	cout << ans << endl;
  }
}