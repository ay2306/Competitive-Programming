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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int p(char a){
    switch(a){
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '^': return 5;
    }
}

void solve(){
    string a;
    cin >> a;
    stack<char> s;
    string ans = "";
    for(auto i: a){
        if(i!='(' && i!=')' && i!='+' && i!='*' && i!='-' && i!='/' && i!='^'){
            ans+=i;
        }else if(i == '('){
            s.push(i);
        }else if(i == ')'){
            while(s.size()){
                char b = s.top();
                s.pop();
                if(b=='(')break;
                ans+=b;
            }
        }else{
            while(s.size() && p(s.top()) > p(i)){
                char b = s.top();
                s.pop();
                if(b!='(')ans+=b;
                else{
                    s.push('(');
                    break;
                }
            }
            s.push(i);
        }
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}