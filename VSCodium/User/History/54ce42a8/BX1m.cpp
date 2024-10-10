#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n>>k;
        int m=n;
        int count=0;

        while(k>0 ){
            k=k-n;
            if(n!=m and k>0){
                k=k-n;
                count++;
            }
            n--;
            count++;
            
        }

        cout << count << endl;
        count=0;
    }
    return 0;
}
