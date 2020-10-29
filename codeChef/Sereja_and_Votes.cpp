#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,n,sum = 0,cnt = 0;
        scanf("%d",&n);
        vector<int> arr;
        while(n--){
            scanf("%d",&a);
            cnt+=!!a,sum+=a;
        }
        if(sum >= 100 && sum < 100 + cnt)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}