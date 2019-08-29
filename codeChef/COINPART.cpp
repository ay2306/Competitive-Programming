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

bool cmp(PII a, PII b){
    return a.first >= b.first;
}

void solve(){
    unordered_map<int,int> m;
    int n;
    cin >> n;
    PII *arr = new PII[n];
    loop(i,0,n){
        int a;
        cin >> a;
        arr[i] = mp(a,i);
    }
    sort(arr,arr+n,cmp);
    int l = 0;
    int k = n-1;
    PII *ans = new PII[n];
    int Asum = 0;
    int Bsum = 0;
    for(int i = 0; i < n; ++i){
        if(Asum <= Bsum){
            ans[i] = arr[l];
            Asum+=arr[l].first;
            l++;
        }else{
            ans[i] = arr[k];
            Bsum+=arr[k].first;
            k--;
        }
        m[ans[i].second] = i;
    }
    vector<int> ANS(n);
    for(auto it : m){
        ANS[it.first] = it.second + 1;
    }
    for(auto it : ANS){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}