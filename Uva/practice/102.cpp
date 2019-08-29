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
    FAST
    // FILE_READ
    int arr[9];
    while(1){
        string s = "BCG";
        string sans = s;
        if(cin >> arr[0]){

        }else{
            break;
        }
        for(int i = 1; i < 9; ++i)cin >> arr[i];
        int ans = INT_MAX;
        do{
            int c = 0;
            for(int i = 0; i < 3; ++i){
                if(s[i] == 'G'){
                    c+=arr[(i*3)];
                    c+=arr[(i*3)+2];
                }
                if(s[i] == 'B'){
                    c+=arr[(i*3)+2];
                    c+=arr[(i*3)+1];
                }
                if(s[i] == 'C'){
                    c+=arr[(i*3)];
                    c+=arr[(i*3)+1];
                }
            }
            // cout << s << " " << c << "\n";
            if(c < ans){
                sans = s;
                ans = c;
            }else if(c==ans && sans > s){
                sans = s;
            }
        }while(next_permutation(s.begin(),s.end()));
        cout << sans << " " << ans << "\n"; 
    }
    return 0;
}