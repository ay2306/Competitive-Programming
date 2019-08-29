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
#define all(a) a.begin(),a.end()
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        string odd = "";
        string even = "";
        for(auto &i: a){
            if((i-'a')%2)odd+=i;
            else even+=i;
        }
        sort(all(even));
        sort(all(odd));
        string ans = odd+even;
        bool p1 = true;
        loop(i,1,ans.size()){
            if(abs(ans[i]-ans[i-1]) == 1){
                p1 = false;
                break;
            }
        }
        bool p2 = !p1;
        if(p2){
            ans = even + odd;
            loop(i,1,ans.size()){
                if(abs(ans[i]-ans[i-1]) == 1){
                    p2 = false;
                    break;
                }
            }
        }
        if(p1 || p2){
            cout << ans << "\n";
        }else{
            cout << "No answer\n";
        }
    }
  return 0;
}
