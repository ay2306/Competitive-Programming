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
#define MAXN 1001000
using namespace std;
int main(){
    // FILE_READ_IN
    // FILE_READ_OUT
    while(1){
        // cout << "NEW ENTRY\n";
        int m,d;
        double dp,pr;
        cin >> m >> dp >> pr >> d;
        if(m <= 0)break;
        double owes = pr;
        pr+=dp;
        dp = owes/m;
        double dec = 0;
        pair<int,double> *arr = new pair<int,double>[d];
        loop(i,0,d){
            int a;
            double b;
            cin >> a >> b;
            arr[i] = mp(a,b);
        }
        sort(arr,arr+d);
        int j = 0,i;
        if(arr[j].first == 0){
            pr *= (1-arr[j].second);
            dec = arr[j].second;
            ++j;
        }
        int flag = 1;
        if(owes < pr){
            cout << "0 months\n";
            flag = 0;
        }
        for(i = 1; i <= m && flag; ++i){
            // cout << "OWES =  " << owes << "  CURRENT_CAR = " << pr << endl;
            if(owes < pr){
                if(i != 1)cout << i-1 << ((i == 2)?" month\n":" months\n");
                else cout << "1 month\n";
                flag = 0;
                break;
            }
            if(arr[j].first == i){
                dec = arr[j].second;
                if(j+1 < d)++j;
            }
            pr*=(1-dec);
            owes-=dp;
        }
        if(flag){
            cout << m << ((m == 1)?" month\n":" months\n");
        }
    }
    return 0;
}