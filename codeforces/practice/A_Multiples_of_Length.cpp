#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a)cin >> i;
    if(n == 1){
        cout << "1 1\n0\n1 1\n0\n1 1\n"<< -a[0] << "\n";
        return 0;
    }
    map<int,int> val;
    for(int x = 0; x < n; ++x)val[x*(n-1)%n] = x;
    cout << "1 " << n-1 << "\n";
    for(int i = 0; i < n-1; ++i){
        int rem =  abs(a[i]) % n;
        if(a[i] > 0)rem = (n - rem) % n;
        cout << val[rem]*(n-1) << " ";
        a[i]+=val[rem]*(n-1);
    }
    cout << "\n2 " << n << "\n";
    for(int i = 1; i < n; ++i){
        int rem =  abs(a[i]) % n;
        if(a[i] > 0)rem = (n - rem) % n;
        cout << val[rem]*(n-1) << " ";
        a[i]+=val[rem]*(n-1);
    }
    cout << "\n1 " << n << "\n";
    for(int i = 0; i < n; ++i)cout << -a[i] << " ";
    return 0;
}