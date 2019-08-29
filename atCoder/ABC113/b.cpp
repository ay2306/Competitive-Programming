#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double a,t;
    cin >> n >> t >> a;
    int mxi = 1;
    vector<double> arr(n+1);
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    for(int i = 2; i <= n; ++i){
        if(abs(a-t+(0.006*arr[i])) < abs(a-t+(0.006*arr[mxi])))mxi = i; 
    }
    cout << mxi;
}