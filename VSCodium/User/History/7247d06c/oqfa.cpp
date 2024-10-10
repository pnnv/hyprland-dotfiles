#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void snu() {
	vector <int> v(4);
	for(auto &i: v) cin >> i;
	swap(v[1], v[2]);
	vector <int> v2 = v, v3 = v, v4 = v;
	swap(v2[0], v2[2]);
	swap(v3[1], v2[3]);
	swap(v4[0], v4[2]); swap(v4[1], v4[3]);
	int w = 0;
	{
		int a = 0, b = 0;
		for(int i = 1; i < 4; i += 2) {
			if(v[i] > v[i - 1]) a++;
			else if(v[i] < v[i - 1]) b++;
		}
		if(a < b) w++;
	}
	v = v2;
	{
		int a = 0, b = 0;
		for(int i = 1; i < 4; i += 2) {
			if(v[i] > v[i - 1]) a++;
			else if(v[i] < v[i - 1]) b++;
		}
		if(a < b) w++;
	}
	v = v3;
	{
		int a = 0, b = 0;
		for(int i = 1; i < 4; i += 2) {
			if(v[i] > v[i - 1]) a++;
			else if(v[i] < v[i - 1]) b++;
		}
		if(a < b) w++;
	}
	v = v4;
	{
		int a = 0, b = 0;
		for(int i = 1; i < 4; i += 2) {
			if(v[i] > v[i - 1]) a++;
			else if(v[i] < v[i - 1]) b++;
		}
		if(a < b) w++;
	}
	cout << w << endl;
}

int32_t main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) snu();
}