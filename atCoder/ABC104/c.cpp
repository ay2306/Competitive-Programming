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
#define MAXN 25
using namespace std;

int main(){
    ll d,g;
    cin >> d >> g;
    // map<ll,ll> m;
    // map<ll,ll> m2;
    g/=100;
    PLL *p = new PLL[d+1];
    P<double,int> *arr = new P<double,int>[d+1];
        map<double,int> m;
        bool *vis = new bool[d+1];
    loop(i,1,d+1){
        ll a,b;
        cin >> a >> b;
        b/100;
        p[i].first = a;
        p[i].second = b;
        arr[i].first = (a*i + b)/a;
        arr[i].second = a;
        m[arr[i].first] = i;
        vis[i] = false;
    } 
    sort(arr,arr+d);
    ll score = 0;
    ll probs = 0;
    ll probs1 = 0;
    // sort(p,p+d);
    // // for(int i = d-1; i >= 0; --i)cout << p[i].first << " ";
    for(ll i = d; i > 0; --i){
        if(score + p[i].first*i <= g){
            probs+=p[i].first;
            score+=(p[i].first*i);
            score+=p[i].second;
        }else {
            ll k = g - score;
            k/=(i);
            probs+=k;
            score = g;
        }
        if(score >= g){
            break;
        }
    }
    ll score1 = 0;
    for(ll i = d; i > 0; ++i){
        if(arr[i].first * arr[i].second  + score1 <= g){
            probs1 += arr[i].second;
            cout << probs1 << endl;
            score1 += arr[i].first*arr[i].second;
            vis[m[arr[i].first]] = true;
        }else{
            int k = m[arr[i].first];
            int req = g-score1;
            int j = d;
            for(; j > k ; --j)if(vis[j] == false)break;
            req/=j;
            probs1+=req;
            cout << probs1 << endl;
            break;
        }
        if(score >= g)break;
    }
    cout << min(probs1,probs);

    // cout << endl;
    // cout <<  probs;
    return 0;
}