#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(),x.end()
/*------------------------------------------------------------------------------------------------------*/

        
void solve()
{   
    ll n,m,q; cin >> n >> m >> q;
    vector<ll> v(m);
    for(auto & i : v) cin >> i;
    sort(all(v));
    while(q--){
        ll pos; cin >> pos;
        if(pos<v[0]){
            cout << v[0]-1 << '\n';
            continue;
        }
        if(pos>v[m-1]){
            cout << n-v.back();
            continue;
        }
        ll l,r;
        l = *(upper_bound(all(v),pos) - 1);
        r = *(upper_bound(all(v),pos));
        ll ans = (r-l)/2;
        cout << ans << '\n' ;
    }
    
}
     
int main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int t;
    cin >> t ;
    while(t--)
    solve() ;    
     
}
