#include<bits/stdc++.h>
using namespace std;
unordered_map<long long int, long long int> m;

long long int f(long long int n){
    if(n == 0)return 0;
    if(m.find(n) == m.end())m[n] = max(n,f(n/2)+f(n/3)+f(n/4));
    return m[n];
}
int main(){
    long long int n;
    cin >> n;
    while(1){
        cout << f(n) << "\n";
        if(cin >> n){

        }else{
            break;
        }
    }
    return 0;
}