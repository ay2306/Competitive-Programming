#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans = 0;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int &i: arr)scanf("%d",&i);
        sort(arr.begin(),arr.end());
        for(int i = 0; i < n; ++i)if(arr[i] <= i+1)ans=i+1;
        printf("%d\n",ans+1);
    }
    return 0;
}