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
#define MAXN 1001000
using namespace std;

int main(){
    // FILE_READ
    while(1){
        int n;
        cin >> n;
        if(n == 0)break;
        while(1){
            int flag = 1;
            vector<int> arr(n);
            cin >> arr[0];
            if(arr[0] == 0){
                cout << "\n";
                break;
            }
            for(int i = 1; i < n; ++i)cin >> arr[i];
            stack<int> s;
            int coach = 1, i = 0;
            while(coach <= n){
                s.push(coach);
                while(!s.empty() && s.top() == arr[i]){
                    s.pop();
                    ++i;
                    if(i >= n)break;
                }
                coach++;
            }
            if(s.empty())cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}