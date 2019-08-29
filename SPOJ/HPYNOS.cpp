#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n,s=0;
    cin  >> n;
    unordered_map<ll,int> m;
    while(n != 1){
        if(m.find(n) != m.end())break;
        m[n]++;
        ll k = 0;
        while(n){
            k+=((n%10)*(n%10));
            n/=10;
        }
        n = k;
        s++;
    }
    if(n == 1){
        cout << s << "\n";
    }else{
        cout << -1 << "\n";
    }
    return 0;
}