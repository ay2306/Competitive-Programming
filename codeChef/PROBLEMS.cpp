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
#define MAXN 1000000000000
using namespace std;

bool cmp(P<int,int> a, P<int,int> b){
    if(a.first > b.first)return false;
    if(a.first < b.first)return true;
    return a.second < b.second;
}

int main(){
    int n,s;
    cin >> n >> s;
    P<int,int> *p = new P<int,int>[n];
    for(int i = 0; i < n; ++i){
        V<P<int,int> > tmp;
        int a;
        for(int j = 0; j < s; ++j){
            cin >> a;
            tmp.pb(mp(a,1));
        }
        for(int j = 0; j < s; ++j){
            cin >> a;
            tmp[j].second = a;
        }
        sort(tmp.begin(),tmp.end());
        // for(int j = 0; j < s; ++j){
        //     cout << "(" << tmp[j].first << ", " << tmp[j].second << ") ";
        // }
        // cout << endl;
        int diff = 0;
        for(int j = 1; j < s; ++j){
            if(tmp[j].second < tmp[j-1].second)diff++;
        }
        p[i]=mp(diff,i+1);
    }
    sort(p,p+n,cmp);
    // for(int i = 0; i < n; ++i){
    //     cout << "(" << p[i].first << ", " << p[i].second << ") ";
    // }
    // cout << endl;
    for(int i = 0; i < n; ++i){
        cout << p[i].second << endl;
    }
}