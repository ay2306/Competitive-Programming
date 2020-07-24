#include<bits/stdc++.h>
using namespace std;
int n,m;
int power(int a, int N){
    if(N == 0)return 1;
    if(N == 1)return a;
    int p = power(a,N/2);
    p *= p;
    if(N&1)p*=a;
    return p%m;
}
int main(){
    cin >> n >> m;
    cout << power(n,m-2);
}