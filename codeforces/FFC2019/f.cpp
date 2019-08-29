#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        int n,s;
        cin >> n >> s;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i)cin >> arr[i];
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int c = 0;
            unordered_map<int,int> m;
            for(int j = i; j < n; ++j){
                m[arr[j]]++;
                if(m[arr[j]] == s+1)c-=s;
                else if (m[arr[j]] <= s)c++;
                ans = max(ans,c);
            }
        }
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}