#include<bits/stdc++.h>
using namespace std;

int arr[9000];
int f[9000],cnt[9000];
int main(){
    int n,t,sum;
    scanf("%d\n",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i)scanf("%d",arr+i),f[i] = 0, cnt[i] = 0;
        for(int i = 1; i <= n; ++i)f[arr[i]]++;
        for(int i = 1; i <= n; ++i){
            sum = arr[i];
            for(int j = i+1; j <= n; ++j){
                sum+=arr[j];
                if(sum > n)break;
                if(f[sum] != 0)cnt[sum]++;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)ans+=cnt[arr[i]] > 0;
        printf("%d\n",ans);
    }
    return 0;
}