#include<bits/stdc++.h>
#define ll long long 
#define pb emplace_back
#define mp make_pair
#define V vector
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define xx first
#define yy second
#define all(a) a.begin(),a.end()
#define loop(a,b,c) for(int a = b; a < c; ++a)
using namespace std;

const int N = 1e9;
const int mod = 1e9+7;
const long double pi = acos(-1.0);
int solve(){
    int f[26] = {0},n,k;
    cin >> n >> k;
    string a;
    cin >> a;
    for(char &i: a)f[i-'a']++;
    string ans = "";
    vector<pair<char,int>> arr;
    for(int i = 0; i < 26; ++i){
        if(f[i])arr.emplace_back(char(i+'a'),f[i]);
    }
    int found = false;
    for(auto &i: arr){
        if(i.second % k != 0 && !found){
            found = true;
            ans += string((i.second+k-1)/k,i.first);
        }else if(found){
            ans.pop_back();
            ans+=i.first;
            return cout << ans << "\n",0;
        }else{
            ans+=string(i.second/k,i.first);
        }
    }
    cout << ans << "\n";
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}