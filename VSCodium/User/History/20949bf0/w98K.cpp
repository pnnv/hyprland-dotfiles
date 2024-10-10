
#include <bits/stdc++.h>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define sz(s) (int)(s.size())
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define os(x) cout << x << " ";
#define out(x) cout << x << endl;
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define COUNT(x,u) count(all(x), u)
#define B break
#define C continue
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x
#define endl '\n'

//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int> st;
typedef priority_queue<ll> pqll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

// Operator overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template<typename T, typename V> // cout << map<T,T>
ostream& operator<<(ostream &ostream, const map<T,V> &c) { for (auto &it : c) cout << it.first << " " << it.second<<endl; return ostream; }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

//Constants
vector <ll> primes;
vector <bool> is_prime;
// Mathematical functions
void Sieve(int n){ is_prime.assign(n + 1, true); is_prime[0] = is_prime[1] = false; for(ll i = 2; i * i <= n; i++) if(is_prime[i]) for(ll j = i * i; j <= n; j += i) is_prime[j] = false;}
void get_primes(int n){ for(int i = 2; i <= n; i++)  if(is_prime[i])  primes.push_back(i); }
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll modinv(ll p,ll q){ll ex;ex=M-2;while (ex) {if (ex & 1) {p = (p * q) % M;}q = (q * q) % M;ex>>= 1;}return p;}
vector<ll> getBin(ll a){
    vector<ll> ans(64,0);
    for(ll i=0;i<64;i++) ans[i]=((a>>i)&1LL);
    return ans;
}
static bool cmp(pl &a,pl &b){
    if((a.first*a.second)==(b.first*b.second)) return (a.first+a.second)>(b.first+b.second);
    return (a.f*a.s)<(b.f*b.s);
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    vpl arr;
    for(int i=0;i<n;i++){
        ll h,w;
        cin>>h>>w;
        arr.pb({min(h,w),max(h,w)});
    }
    sort(all(arr),cmp);
    //for(auto it:arr) cout<<it.f<<" "<<it.s<<endl;
    vvl dp(n,vl(k+1,-1));
    function<ll(ll,ll)> f=[&](ll i,ll k)->ll{
        if(k==0) return 0;
        if(i==n) return 1e9;
        if(dp[i][k]!=-1) return dp[i][k];
        function<ll(ll,ll,ll)> mini=[&](ll r,ll c,ll k){
            ll ans=1e9;
            for(int i=1;i<=c;i++){
                ans=min(ans,i*r + max(0LL,(k-i)*(c-i)));
            }
            return ans;
        };
        ll skip=f(i+1,k);
        ll pick=1e9;
        if(arr[i].f + arr[i].s>k){
            pick=mini(arr[i].f,arr[i].s,k);
        }
        else pick=(arr[i].f*arr[i].s) + f(i+1,k-(arr[i].f+arr[i].s));
        return dp[i][k]=min(skip,pick);

    };
    ll ans=f(0,k);
    if(ans>=1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=k;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }


    // ll ans=0;
    // for(int i=0;i<n && k>0;i++){
    //     auto curr=arr[i];
    //     if(curr.s + curr.f>=k){
    //         function<ll(ll,ll,ll)> mini=[&](ll r,ll c,ll k){
    //             ll ans=1e9;
    //             for(int i=1;i<=c;i++){
    //                 ans=min(ans,i*r + max(0LL,(k-i)*(c-i)));
    //             }
    //             return ans;
    //         };
    //         ans+=mini(curr.f,curr.s,k);
    //         k=0;
    //         break;
    //     }
    //     else{
    //         k-=curr.s+curr.f;
    //         ans+=curr.s*curr.f;
    //     }
    //     //cout<<ans<<endl;
    // }
    // if(k>0) cout<<-1<<endl;
    // else cout<<ans<<endl;


}

int32_t main()
{
    fastio()
    #ifndef ONLINE_JUDGE
        freopen("Error.txt","w",stderr);
    #endif
    
    int t=1;
    cin>>t;
    while(t--)
    {
    solve();
    }
    return 0;  
}

