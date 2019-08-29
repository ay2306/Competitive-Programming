#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        bool free = true;
        int n,k;
        cin >> n >> k;
        int tcnt = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            int a,b;
            cin >> a >> b;
            if(a+tcnt <= k){tcnt+=a;}
            else if(free){
                free = false;
                tcnt+=a;
                cnt+=((tcnt-k)*b);
            }else{
                cnt+=(a*b);
            }
        }
        cout << cnt << endl;
    }
return 0;
}