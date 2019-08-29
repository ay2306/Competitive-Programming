/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
ll dp[2010][2010][2];
//dp[pos][remainder][state]
// pos: it tell the decimal place where I am putting a number
// remainder: It tell the remainder I have from placing previous digits
// state: 0 means that by placing previous digits it is guaranteed that number is now smaller than num vector
//        1 means that it is currently equal to all the num vector digits
ll rem[2010];
//rem array stores the following
//rem[i] = (10**i)%m
int d,m;
vector<int> num;

//Binary modular exponentiation so that I can calculate (10**x)%m
ll bme(ll a, ll n){
    if(n == 0)return 1;
    if(n==1)return a%m;
    ll k = bme(a,n/2);
    k*=k;
    if(n%2==1){
        k*=a;
    }
    k = k%m;
    return k;
}

//Function to solve the problem
ll solve(int pos, int Rem, int f){
    if(pos == num.size()){
        if(Rem == 0)return 1;
        return 0;
    }
    if(dp[pos][Rem][f] != -1)return dp[pos][Rem][f];
    int LM;
    if(f) LM = 9;
    else LM=num[pos];
    ll res = 0;
    for(int i = 0; i <= LM; ++i){
        //Continue if its d and its and odd(1 based index)
        if(i == d && pos%2 == 0)continue;
        //Continue if its not d and its and even(1 based index)
        else if(i != d && pos%2 == 1)continue;
        int nf = 0;
        //From principle that a*b = (a%m*b%m)%m;;
        //5000 = 5*1000
        //5000%m = (5%m*rem[3])%m;
        int krem = ((i%m)*(rem[num.size()-1-pos]%m))%m;
        krem = (krem%m + Rem%m)%m;
        //State is equal if place equal to num[pos]
        if(i == num[pos] && f == 0)res=(res + solve(pos+1,krem,0))%MOD;
        //State is smaller if place number less than num[pos]
        else res = (res + solve(pos+1,krem,1))%MOD;
    }
    dp[pos][Rem][f] = res;
    return dp[pos][Rem][f];
}

int main(){
    cin >> m >> d;
    string a,b;
    cin >> a >> b;
    for(int i = 0; i < 2010; ++i){
        rem[i] = bme(10,i);
    }
    // for(int i = 0; i < 5; ++i){
    //     cout << rem[i] << " " ;
    // }
    // cout << "\n";
    num.clear();
    for(auto i: a){
        num.pb(int(i-'0'));
    }
    memset(dp,-1,sizeof(dp));
    int k = num.size()-1;
    if(num[k] == 0){
        do{
            num[k] = 9;
            k--;
        }while(k >= 0 && num[k] == 0);
        num[k]--;
    }else{
        num[k]--;
    }
    // for(auto i : num){
    //     cout << i ;
    // }
    // cout << endl;
    ll s1 = solve(0,0,0);
    num = vector<int>();
    memset(dp,-1,sizeof(dp));
    for(auto i: b){
        num.pb(int(i-'0'));
    }
    // for(auto i : num){
    //     cout << i ;
    // }
    // cout << endl;
    ll s2 = solve(0,0,0);
    // cout << s1 << " " << s2 << "\n";
    cout << ((s2%MOD - s1%MOD)+MOD)%MOD;
    return 0;
}