#include<iostream>
#define ll unsigned long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a;
        cin >> a;
        ll b;
        ll sum1 = 0;
        ll sum2 = 0;
        ll *arr1 = new ll[a];
        ll *arr2 = new ll[a];
        for(ll i = 0; i < a; ++i)cin >> arr1[i];
        for(ll i = 0; i < a; ++i)cin >> arr2[i];
        for(ll i = 0; i < a; ++i){
            if(i%2==0){
                sum1+=arr1[i];
                sum2+=arr2[i];
            }else{
                sum1+=arr2[i];
                sum2+=arr1[i];
            }
        }
        cout << ((sum1>sum2)?sum2:sum1) << endl;
    }
    return 0;
}