#include<bits/stdc++.h>
using namespace std;

long long f(long long a, long long b){
    if(abs(a-b) <= 1)return 0;
    return b-a;
}

int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long ans = 0;
    for(int i = 0; i < n; ++i)cin >> arr[i];
    for(int i = 0; i < n; ++i)
        for(int j = i; j < n; ++j)ans+=f(arr[i],arr[j]);
    cout << ans << "\n";
    return 0;
}