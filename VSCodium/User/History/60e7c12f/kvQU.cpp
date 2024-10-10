#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, x, y;
    cin >> d >> x >> y;
    int count = 0;
    int mauka = 1;
    while (x > y) {
      count++;
      y--;
      x = x - (x * d * mauka) / 100;
      mauka++;
      if (d * mauka >= 100 && x > y) {
        cout << -1 << endl;
        break;
      }
    }

    if (x <= y) {
      cout << count << endl;
    }
  }
}