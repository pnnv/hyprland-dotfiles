#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, x, y;
    cin >> d >> x >> y;
	if(y >= x) {
		cout << 0 << endl;
		continue;
	}
	
    int count = 0;
    int mauka = 0;
	int ans = -1;
    while (y > 0) {
      count++;
      y--;
	  mauka += d;
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