//https://codeforces.com/contest/612/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int n,p,q;
    cin >> n >> p >> q >> a;
    for(int x = 0; x <= 100; ++x){
        for(int y = 0; y <= 100; ++y){
            if(x*p + y*q != n)continue;
            cout << x+y << "\n";
            for(int i = 0; i < x; ++i){
                for(int j = 0; j < p; ++j)cout << a[i*p+j];
                cout << "\n";
            }
            for(int i = 0; i < y; ++i){
                for(int j = 0; j < q; ++j)cout << a[x*p+i*q+j];
                cout << "\n";
            }
            return 0;
        }
    }
    return cout << -1,0;
}