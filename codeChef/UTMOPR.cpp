#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        unsigned long long int a;
        int n,k;
        cin >> n >> k;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            cin >> a;
            cnt+=(a%2);
        }
        if(k>1)cout << "even\n";
        if(k==1){
            if(cnt%2==0)cout << "odd\n";
            else{cout << "even\n";}
        }
    }
return 0;
}