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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

int main(){
    // FILE_READ
    string a;
    cin >> a;
    int c = 0;
    int j = -1;
    for(int i = 0; i < a.length(); ++i){
        if(int(a[i] - '0')%3 == 0){
            c++;
            j = i;
            continue;
        }
        if(i-1 == j)continue;
        if(i-2 == j){
            int l = int(a[i-1]-'0')%3;
            int m = int(a[i]-'0')%3;
            if(l != m){
                c++;
                j = i;
            }
        }
        if(i-3 == j){
            j = i;
            c++;
        }
    }
    cout << c;
    return 0;
}