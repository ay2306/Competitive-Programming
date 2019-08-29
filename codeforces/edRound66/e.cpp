#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int,int> m;
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0;i < n; ++i){
        cin >> arr[i];
        if(m[arr[i]-1] > 0){
            m[arr[i]-1]--;
        }else{
            ans++;
        }
        m[arr[i]]++;
    }
    cout << ans;
    return 0;
}