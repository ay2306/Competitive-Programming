//https://codeforces.com/contest/1173/problem/D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;
const ll mod = 998244353;
vector<int> g[N];
int n,a,b;
ll fact[N];

/*
    I should explain what I did, else I will not remember logic of this question
    Let's say we fix a root for this tree to be (12 o'clock point) top of circle
    or say first element of the permutation
    Then rest are just any permuation this 
    [root {subtree1 permutations} {subtree2 permuations}]
    unlike root no other point is fixed
    there for root F(root) = F(SB1)*F(SB2)... * (SUB[ROOT]-1)!
    for else F(u) = F(SB1)*F(SB2)... * (SUB[u])!
    I don't know how mathematically but when I drew a few sample trees
    rerooting got them same result in the end
    So calculate for one root and ans = n*F(root);
*/

ll dfs(int s = 1, int p = -1){
    ll ans = 1,cnt = (p != -1);
    for(int &i: g[s]){
        if(i!=p)ans=ans*dfs(i,s)%mod,cnt++;
    }
    return ans*fact[cnt]%mod;
}

int main(){
    fact[0] = 1;
    for(int i = 1; i < N; ++i)fact[i] = fact[i-1]*i%mod;
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    return printf("%lld",n*dfs()%mod),0;
}