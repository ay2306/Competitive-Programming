#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ans = 0;
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(auto &i: arr)scanf("%d",&i);
        int mx = *max_element(arr.begin(),arr.end());
        unordered_map<int,int> m;
        for(int i = 0; i < n/2; ++i)m[arr[i]]++;
        if(m[mx] == 0)ans++;
        int to_remove = n/2-1;
        int to_add = n-1;
        while(to_add > 0){
            m[arr[to_remove]]--;
            m[arr[to_add]]++;
            if(m[mx] == 0)ans++;
            to_remove = (to_remove - 1 + n)%n;
            to_add = (to_add - 1 + n)%n;
        }
        printf("%d\n",ans);
    }
    return 0;
}