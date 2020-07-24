#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long a,n;
        scanf("%lld",&n);
        long long ans = 0;
        map<long long,long long> m;
        for(int i = 0; i < n; ++i){
            scanf("%lld",&a);
            m[a]++;
        }
        for(int i = 0; i < n; ++i){
            scanf("%lld",&a);
            m[a]--;
        }
        vector<int> A,B;
        for(auto i: m){
            if(abs(i.second)&1){
                ans = -1;
                goto printHere;
            }
            if(i.second < 0){
                for(int j = 0; j < abs(i.second)/2; ++j)A.emplace_back(i.first);
            }
            if(i.second > 0){
                for(int j = 0; j < abs(i.second)/2; ++j)B.emplace_back(i.first);
            }
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        while(A.size()){
            ans+=min(A[0],B.back());
            A.erase(A.begin());
            B.pop_back();
        }
        printHere:
        printf("%lld\n",ans);
    }
    return 0;
}