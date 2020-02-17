#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,q;
    cin >> n >> q;
    vector<long long int> arr(n);
    for(auto &i: arr)cin >> i;
    sort(arr.begin(),arr.end());
    while(q--){
        long long int a;
        cin >> a;
        auto it = upper_bound(arr.begin(),arr.end(),a);
        if(it == arr.begin()){
            cout << -1 << "\n";
        }else{
            cout << *prev(it) << "\n";
        }
    }
}