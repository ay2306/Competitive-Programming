#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll a = abs(A), b = abs(B), c = abs(C);
    if(a == 0 && c%b != 0)return cout << -1,0;
    if(a == 0)cout << 1 << " " << C/B,0;
    if(b == 0 && c%a != 0)return cout << -1,0;
    if(b == 0)cout << C/A << " " << 1,0;
    

}