    //https://codeforces.com/contest/895/problem/C
    #include<bits/stdc++.h>
    using namespace std;
    const int N = 1e5+10,MAX_A = 70,mod=1e9+7;
    int n,t,a,mask[MAX_A+1],dp[MAX_A+1][1<<19],mx=(1 << 19);
    long long pos[MAX_A+1][2]; //pos[i][0] = number of ways to select even numbers of i
    bool isPrime(int a){
        for(int i = 2; i*i <= a; ++i){
            if(a%i==0)return false;
        }
        return true;
    }

    int main(){
        map<int,int> m;
        for(int i = 1; i <= MAX_A; ++i)pos[i][0] = 1;
        for(int i = 2; i <= MAX_A; ++i)if(isPrime(i))m[i]=t++;
        scanf("%d",&n);
        for(int i = 1; i <= n; ++i){
            scanf("%d",&a);
            int k = (pos[a][0] + pos[a][1])%mod;
            pos[a][0] = k, pos[a][1] = k;   
        }
        for(int i = 1; i <= MAX_A; ++i){
            int at = i;
            for(auto &j: m){
                while(at%j.first == 0)mask[i]^=(1<<j.second),at/=j.first;
            }
        }
        dp[0][0] = 1;
        for(int i = 1; i <= MAX_A; ++i){
            for(int msk = 0; msk < mx; ++msk){
                // include i even times
                dp[i][msk] += dp[i-1][msk]*pos[i][0]%mod;
                dp[i][msk^mask[i]] += dp[i-1][msk]*pos[i][1]%mod;
                dp[i][msk] %= mod;
                dp[i][msk^mask[i]] %= mod;
            }
        }
        return printf("%lld",(dp[MAX_A][0]-1+mod)%mod),0;
    }

