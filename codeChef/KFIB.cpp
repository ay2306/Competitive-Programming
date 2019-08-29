#include <iostream>
#define mod 1000000007
using namespace std;

int main(){
    unsigned long long int n,k;
    unsigned long long int sum = 0;
    cin >> n >> k;
    unsigned long long int *a = new unsigned long long int[n];
    for(unsigned long long int i = 0; i < k; ++i){a[i]=1;++sum;}
    if(n<=k)cout << k;
    a[k]=sum;
    else{
        sum = 0;
        for(unsigned long long int i = k; i < n; ++i){
            sum = 0;
            for(unsigned long long int x = 0, j = i-1; x < k; ++x,--j){
                sum+=(a[j]%mod);
            }
            a[i] = sum%mod;
        }
        cout << a[n-1];
    }
return 0;
}
