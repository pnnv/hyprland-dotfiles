#include <bits/stdc++.h>
using namespace std;
     
typedef long long ll;
#define UMP unordered_map
#define UST unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define all(x) x.begin(),x.end()
/*------------------------------------------------------------------------------------------------------*/
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
/*------------------------------------------------------------------------------------------------------*/

        
void solve(){   
    ll n; cin >> n ;
    vector<ll> v(n) ;
    for(auto & i : v) cin >> i ;
    ll sum = accumulate(all(v),0LL) ;
    ll ans = sum ;
    vector<ll> mad(n) ;
    map<ll,ll> mp ;
    mp[v[0]]++ ;
    mad[0] = 0 ;
    for(int i=1; i<n; i++){
        mp[v[i]]++ ;
        if(v[i]>mad[i-1] && mp[v[i]]>1) mad[i] = v[i] ;
        else mad[i] = mad[i-1] ;
    }
    ll cnt = 1 ;
    for(int i=1; i<n; i++){
        if(mad[i]!=mad[i-1]){
            ll res = cnt*mad[i-1] ;
            if(cnt>1) res *= n-i-1 ;
            ans += res ;
            res = (cnt*(cnt+1))/2 ;
            ans += res*mad[i-1] ;
            cnt = 1 ;
        }
        else if(i==n-1){
            ll res = cnt*mad[i] ;
            if(cnt>1) res *= n-i-1 ;
            ans += res ;
            res = (cnt*(cnt+1))/2 ;
            ans += res*mad[i-1] ;
            cnt = 1 ;
        }
        cnt++ ;
    }
    cout << ans << '\n' ;
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
