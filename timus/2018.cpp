#include <bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const ll MOD = 1e9+7;
const int N = 5e4 + 5   ;
ll dp1[N][2];
int main(){
    int n,a,b;
    cin  >> n >> a >> b;
    dp1[0][1] = 1;
    dp1[0][0] = 1;
    loop(i,0,n+1){
        loop(j,1,a+1){
            if(i - j < 0)break;
            dp1[i][0] = (dp1[i][0]%MOD + dp1[i-j][1]%MOD)%MOD;
        }
        loop(j,1,b+1){
            if(i - j < 0)break;
            dp1[i][1] = (dp1[i][1]%MOD + dp1[i-j][0]%MOD)%MOD;
        }
    }
    cout << (dp1[n][0] + dp1[n][1])%MOD << "\n";
   return 0;
}