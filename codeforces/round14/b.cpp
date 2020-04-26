#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define V vector
#define P pair
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define C continue;
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define ld long double
#define xx first
#define yy second
#define fst ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;
int d[1010];
int main(){
    int n,x,a,b,ans = INT_MAX;
    scanf("%d%d",&n,&x);
    loop(i,0,n){
        scanf("%d%d",&a,&b);
        if(a > b)swap(a,b); 
        d[a]++;
        d[b+1]--;
    }
    if(d[0] == n)ans = x;
    loop(i,1,1010){
        d[i]+=d[i-1];
        if(d[i] == n)ans=min(ans,abs(x-i));
    }
    if(ans == INT_MAX)ans = -1;
    return printf("%d",ans),0;
}