#include<iostream>
#define ll unsigned long long int
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,b,m;
        ll time = 0;
        cin >> n >> b >> m;
        int it = 1;
        int br = 0;
        while(n){
            ll k;
            if(n == 1){
                k = 1;
                n = 0;
                time+=(it*m);
                break;
            }
            else if(n%2==0){
                k = n/2;
                n = n/2;
            }else{
                k = (n+1)/2;
                n = n/2;
            }
            br++;
            time+=(it*m*k);
            it*=2;
        }
        time+=(br*b);
        cout << time << endl;
    }
}