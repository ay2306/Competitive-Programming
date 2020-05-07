#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n,v,a,b;
    scanf("%d%d",&n,&v);
    vector<pair<int,int>> A,B;
    for(int i = 1; i <= n; ++i){
        scanf("%d%d",&a,&b);
        if(a == 1)A.emplace_back(b,i);
        else B.emplace_back(b,i);
    }
    sort(A.begin(),A.end(),greater<pair<int,int>> ());
    sort(B.begin(),B.end(),greater<pair<int,int>> ());
    for(int i = 1; i < (int)A.size(); ++i)A[i].first+=A[i-1].first;
    for(int i = 1; i < (int)B.size(); ++i)B[i].first+=B[i-1].first;
    int first = 0, second = 0, ans = 0;
    if(A.size())ans = A[min((int)A.size(),v)-1].first,first = min((int)A.size(),v);
    for(int i = 0; i < B.size() && 2*(i+1) <= v; ++i){
        int rem = v-2*(i+1);
        int s = B[i].first;
        if(rem){
            rem = min((int)A.size(),rem);
            s+=A[rem-1].first;
        }
        if(s > ans)ans = s,first = rem, second = i+1;
    }
    printf("%d\n",ans);
    for(int i = 0; i < first; ++i)printf("%d ",A[i].second);
    for(int i = 0; i < second; ++i)printf("%d ",B[i].second);
    return 0;
}