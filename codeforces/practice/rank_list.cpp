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

using namespace std;

bool comp(PII a, PII b){
    if(a.first > b.first)return true;
    if(a.first < b.first)return false;
    if(a.second <= b.second)return true;
    return false;
}

int main(){
    // freopen("input.txt","r",stdin);
    int n,k;
    int c = 0;
    cin >> n >> k;
    PII *p = new PII[n+1];
    for(int i = 0,a,b; i < n; ++i){
        cin >> a >> b;
        p[i] = mp(a,b);
    }
    sort(p,p+n,comp);
    int r = 1;
    P<PII,int> *v = new P<PII,int>[n+1];
    v[0] = mp(p[0],r);
    for(int i = 1; i < n; ++i){
        if(p[i].first < p[i-1].first){
            r++;
            v[i]=mp(p[i],r);
        }else{
            if(p[i].second > p[i-1].second){
                r++;
                v[i]=mp(p[i],r);
            }else{
                v[i]=mp(p[i],r);
            }
        }
        if(r == k)c++;
    }
    r = v[k-1].second;
    c = 0;
    for(int i = 0; i < n; ++i){
        if(v[i].second == r)c++;
    }
    cout << c;
    return 0;
}