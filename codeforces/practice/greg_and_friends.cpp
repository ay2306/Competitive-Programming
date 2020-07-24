//https://codeforces.com/contest/295/problem/C
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7, N = 110;
int f[N],inv[N];

struct state{
    int small,big,pos,res;
    state(int small = 0, int big = 0, int pos = 0, int res = 0):small(small),big(big),pos(pos),res(res){}
    bool operator<(const state &rhs)const{
        if(res != rhs.res)return res < rhs.res;
        if(small != rhs.small)return small < rhs.small;
        if(big != rhs.big)return big < rhs.big;
        return pos < rhs.pos;
    }
};

int power(int a, int n){
    if(n == 0)return 1;
    if(n == 1)return a;
    int p = power(a, n >> 1);
    p = p * p % mod;
    if(n & 1)p = p * a % mod;
    return p;
}

void pre(){
    f[0] = 1;
    inv[0] = 1;
    f[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < N; ++i){
        f[i] = i * f[i-1] % mod;
        inv[i] = inv[i-1] * power(i,mod-2) % mod;
    }
}

int ncr(int n, int r){
    if(r < 0 || r > n)return 0;
    return f[n] * inv[n-r] % mod * inv[r] % mod;
}  


int n,w,big,small,a;
int dp[N][N][2];
int dis[N][N][2];

int cal(int ways, int smallRem, int smallChoose, int bigRem, int bigChoose){
    return ways * ncr(smallRem,smallChoose) % mod * ncr(bigRem, bigChoose);
}

signed main(){
    cin >> n >> w;
    w/=50;
    if(w == 0)return cout << "-1\n0",0;
    pre();
    for(int i = 0 ; i < n; ++i){
        cin >> a;
        if(a == 50)small++;
        else big++;
    }
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)dis[i][j][0] = INT_MAX, dis[i][j][1] = INT_MAX;
    dp[0][0][0] = 1;
    dis[0][0][0] = 0;
    set<state> s;
    s.emplace(0,0,0,0);
    while(s.size()){
        int lo = s.begin()->small;
        int hi = s.begin()->big;
        int pos = s.begin()->pos;
        int res = s.begin()->res;
        int ways = dp[lo][hi][pos];
        s.erase(s.begin());
        if(pos == 0){
            for(int i = 0; i <= w && i+lo <= small; ++i){
                for(int j = 0; i+2*j <= w && j+hi <= big; ++j){
                    if(i + j == 0)continue;
                    if(dis[i+lo][j+hi][pos^1] >= res + 1){
                        if(dis[i+lo][j+hi][pos^1] > res+1){
                            s.erase(state(i+lo,j+hi,pos^1,dis[i+lo][j+hi][pos^1]));
                            dis[i+lo][j+hi][pos^1] = res+1;
                            dp[i+lo][j+hi][pos^1] = cal(ways,small-lo,i,big-hi,j);
                            s.insert(state(i+lo,j+hi,pos^1,dis[i+lo][j+hi][pos^1]));
                        }else{
                            dp[i+lo][j+hi][pos^1] += cal(ways,small-lo,i,big-hi,j);
                            if(dp[i+lo][j+hi][pos^1] >= mod)dp[i+lo][j+hi][pos^1] -= mod;
                        }
                    }
                }
            }
        }else{
            for(int i = 0; i <= w && i <= lo; ++i){
                for(int j = 0; i+2*j <= w && j <= hi; ++j){
                    if(i + j == 0)continue;
                    int X = lo - i;
                    int Y = hi - j;
                    if(dis[X][Y][pos^1] >= res + 1){
                        if(dis[X][Y][pos^1] > res+1){
                            s.erase(state(X,Y,pos^1,dis[X][Y][pos^1]));
                            dis[X][Y][pos^1] = res+1;
                            dp[X][Y][pos^1] = cal(ways,lo,i,hi,j);
                            s.insert(state(X,Y,pos^1,dis[X][Y][pos^1]));
                        }else{
                            dp[X][Y][pos^1] += cal(ways,lo,i,hi,j);
                            if(dp[X][Y][pos^1] >= mod)dp[X][Y][pos^1] -= mod;
                        }
                    }
                }
            }
        }    
    }
    if(dis[small][big][1] == INT_MAX)return cout << "-1\n0", 0;
    return cout << dis[small][big][1] << "\n" << dp[small][big][1] << "\n",0;
}