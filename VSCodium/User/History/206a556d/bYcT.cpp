#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define double long double
#define zll uint64_t
#define all(x) x.begin(), x.end()
#define rall(x) (x).begin(),(x).end(),greater<int>()
#define vin(a) for(int i=0;i<(a).size();i++)cin>>a[i];
#define vout(a) for(int i=0;i<a.size();i++)cout<<a[i]<<' ';cout<<endl;
#define vl vector<ll> 
#define pb push_back
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pa cout << ans << endl
#define endl '\n'
#define ret(msg) cout << msg << '\n'; return
#define  ff first
#define  ss second
#define mod 1000000007
int mayb(vector<ll> a, string s){
    ll n=a.size();
    ll ovr=0;
    if(s.length()!=a.size()){
        return 0;
        ovr=1;
    }
map<char,ll> spr;
map<ll,ll> npr;
map<char,ll> join;
ll len=0;
for(int i=0;i<n;i++){
    if(spr[s[i]]==0){
        if(npr[a[i]]==0){
            spr[s[i]]++;
            npr[a[i]]++;
            len++;
            join[s[i]]=a[i];
        }
        else{
            ovr=1;
        }
    }
    if(spr[s[i]]>0){
        if(a[i]!=join[s[i]]){
            ovr=1;
        }
        else{
            len++;
        }
    }
}
if(ovr)return 0;

else return 1;

}

void solve(){
ll n; cin>>n;
vector<ll> a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
ll q; cin>>q;
while(q--){
    string s;
    cin>>s;
    if(mayb(a,s)){
        py;
    }
    else{
        pn;
    }
   


}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
 cin>>t;
    for(int i = 1; i<=t; i++){
    // cout<<"Case #"<<i<<": ";
        solve();}
  
    return 0;
}