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

int getSingle(int a){
    if(a < 10)return a;
    int c = 0;
    while(a){
        c+=(a%10);
        a/=10;
    }
    return getSingle(c);
}

int main(){
    // FILE_READ
    string a,b;
    getline(cin,a);
    while(1){
        getline(cin,b);
        // cin >> b;
        int cala = 0;
        int calb = 0;
        for(auto i : a){
            if(i >= 'a' && i <= 'z')cala+=(i-'a'+1);
            if(i >= 'A' && i <= 'Z')cala+=(i-'A'+1);
        }
        for(auto i : b){
            if(i >= 'a' && i <= 'z')calb+=(i-'a'+1);
            if(i >= 'A' && i <= 'Z')calb+=(i-'A'+1);
        }
        double calaa = getSingle(cala);
        double calba = getSingle(calb);
        if(calaa > calba)swap(calaa,calba);
        double p = calaa/calba;
        // cout << p << endl;
        // cout << cala << " " << calb << endl;
        printf("%.2f \%\n",(p)*100);
        // if(cin >> a){
        if(getline(cin,a)){

        }else{
            break;
        }
    }
    return 0;
}