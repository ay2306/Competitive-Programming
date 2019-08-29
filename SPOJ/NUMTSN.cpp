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
 
vector<int> num;
//Num vector to place digit of the number;

ll dp[51][36][36][2][2];
/*
dp[pos][difference_between_three_and_six][difference_between_nine_and_six][if_any_of_3_6_9_included][state]
pos: Position we are setting digit for
state: If previously state digits make number smaller so far or not
*/
ll cal(int pos, int diff_three_six, int diff_six_nine, int included, int f){
    if(pos == num.size()){
        if(included == 1 && diff_three_six == 18 && diff_six_nine == 18)return 1;
        return 0;
    }
    if(diff_three_six < 0 || diff_three_six >= 36 || diff_six_nine < 0 || diff_six_nine >= 36 || included >= 2)return 0;
    if(dp[pos][diff_three_six][diff_six_nine][included][f] != -1)return dp[pos][diff_three_six][diff_six_nine][included][f];
    int LM;
    if(f == 0)LM=num[pos];
    else LM = 9;
    ll res = 0;
    for(int i = 0; i <= LM; ++i){
        int t = diff_three_six;
        int s = diff_six_nine;
        int n = included;
        //If digit is 3, then ofcourse its included
        //Reduce difference between 6 and 3 by 1
        if(i == 3){
            t--;
            n = 1;
        }
        //Increase difference between 6 and 3 by 1
        //Increase difference between 6 and 9 by 1
        if(i == 6){t++;s++;}
        //Decrease difference between 6 and 9 by 1
        if(i == 9)s--;
        if(i == LM && f == 0)res = (res%MOD + cal(pos+1,t,s,n,0)%MOD)%MOD;
        else res = (res%MOD + cal(pos+1,t,s,n,1)%MOD)%MOD;
    }
    dp[pos][diff_three_six][diff_six_nine][included][f] = res;
    return res;
}

/*
Only point to matter beyond this point of code is this:
s1 = cal(0,18,18,0,0);
s2 = cal(0,18,18,0,0);
Set difference to be 18 because negative indices cannot be accessed (I mean it will be more complicated)
Otherwise code is correct, checked on previous TLE implementation:
Link to previous implementation: https://ideone.com/QU52xW
*/

void solve(){
    string a,b;
    cin >> a >> b;
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
    ll s1 = cal(0,18,18,0,0);
    num = vector<int>();
    memset(dp,-1,sizeof(dp));
    for(auto i: b){
        num.pb(int(i-'0'));
    }
    ll s2 = cal(0,18,18,0,0);
    // cout << s1 << " " << s2 << "\n";
    cout << ((s2%MOD - s1%MOD)+MOD)%MOD << "\n";
}
 
int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}