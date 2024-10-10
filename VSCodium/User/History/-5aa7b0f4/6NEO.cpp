#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define sortv(arr) sort((arr).begin(),(arr).end())

int main() {
 // your code goes here
 int t;
 cin>>t;
 while(t--){
     int n,x;
     cin>>n>>x;
     
    // int arr[n];
     vi v;
     for(int i=0; i<n; i++){
         int temp;
         cin>>temp;
         v.push_back(temp);
        // arr[i]=temp;
     }
     sortv(v);
     
     int i=0; int j=n-1;
     while(j>=i){
        if(v[i]>=x) break;  
		if(v[j]<=x) break;
		
		int k = min(v[j]-x, x-v[i]);
		v[i]+=k;
		v[j]-=k;
	
		if(v[i]>=x) i++;
		if(v[j]<=x) j--;
     }
    // for(auto i:v){
    //     cout<<i<<"  ";
    // }
    // cout<<endl;
     int ans=0;
     for(int i=0; i<n; i++){
         if(v[i]>=x){
             ans++;
         }
     }
     cout<<ans<<endl;
 }
 return 0;
}
