#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isPalindrome(int number) {
    // Negative numbers are not palindromes
    if (number < 0) return false;

    // Find the reverse of the number
    int original = number;
    int reversed = 0;

    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    // Check if the original number and the reversed number are the same
    return original == reversed;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
	
	for(int i = 1; i <= 10000; i++) {
		if(isPalindrome(i)) cout << i << endl;
	}
}

1
2
3
4
5
6
7
8
9
11
22
33
44
55
66
77
88
99
101
111
121
131
141
151
161
171
181
191
202
212
222
232
242
252
262
272
282
292
303
313
323
333
343
353
363
373
383
393
404
414
424
434
444
454
464
474
484
494
505
515
525
535
545
555
565
575
585
595
606
616
626
636
646
656
666
676
686
696
707
717
727
737
747
757
767
777
787
797
808
818
828
838
848
858
868
878
888
898
909
919
929
939
949
959
969
979
989
999

