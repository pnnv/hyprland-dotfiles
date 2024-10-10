#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int lli;

int checkMapping(vector<lli> vec, string str) {
    lli size = vec.size();
    lli flag = 0;

    if (str.length() != size) {
        return 0;
        flag = 1;
    }

    map<char, lli> char_map;
    map<lli, lli> num_map;
    map<char, lli> mapping;

    lli count = 0;
    for (int i = 0; i < size; i++) {
        if (char_map[str[i]] == 0) {
            if (num_map[vec[i]] == 0) {
                char_map[str[i]]++;
                num_map[vec[i]]++;
                count++;
                mapping[str[i]] = vec[i];
            } else {
                flag = 1;
            }
        }
        if (char_map[str[i]] > 0) {
            if (vec[i] != mapping[str[i]]) {
                flag = 1;
            } else {
                count++;
            }
        }
    }

    if (flag) return 0;
    else return 1;
}

void solve() {
    lli n; 
    cin >> n;
    vector<lli> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    lli queries; 
    cin >> queries;

    while (queries--) {
        string query_str;
        cin >> query_str;

        if (checkMapping(numbers, query_str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; i++) {
        solve();
    }
    return 0;
}
