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
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int main(){
    int n;
    cin >> n;
    M<int,int> m;
    stack<int> s;
    int *arr = new int[n+1];
    memset(arr,-1,sizeof(int)*(n+1));
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        if(arr[a] == -1){
            arr[a] = i;
        }
        else{
            s.push(i);
        }
    }
    for(int i = n; i > 0; --i){
        if(arr[i] == -1){
            arr[i] = s.top();
            s.pop();
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << arr[i] << " ";
    }
    return 0;
}