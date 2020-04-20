//https://codeforces.com/contest/1333/problem/F
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+2;
int pr[N];
int main(){
    for(int i = 2; i < N; ++i){
        if(pr[i])continue;
        for(int j = i; j < N; j+=i)if(pr[j] == 0)pr[j] = i;
    }
    int n;
    scanf("%d",&n);
    vector<int> a(n-1);
    for(int i = 2; i <= n; ++i)a[i-2]=i/pr[i];
    sort(a.begin(),a.end());
    for(auto &i: a)printf("%d ",i);
    return 0;
}