#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(1,1);
        for(int i = 1; i < n; ++i)
            if(s[i] == s[i-1])arr.back()++;
            else arr.emplace_back(1);
        n = arr.size();
        int i = 0,j = 0,ans=0;
        while(i < n){
            while(j < i)j++;
            while(j < n && arr[j] == 1)j++;
            if(j == n)ans++,i+=2;
            else ans++,arr[j]--,i++;
        }
        cout << ans << "\n";
    }
    return 0;
}