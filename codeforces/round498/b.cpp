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

bool cmp(P<int,int> a, P<int,int> b){
    if(a.first > b.first)return true;
    return false;
}

int main(){
    int t,n,k,a;
    cin >> n >> k;
    ll sum = 0;
    P<int,int> *p = new P<int,int>[n];
    ll *arr = new ll[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        if(n == k){
            sum += arr[i];
        }
        else if(k == 1){
            sum = max(sum,arr[i]);
        }
        p[i] = mp(arr[i],i);
    }
    if(n == k){
        cout << sum << endl;
        for(int i = 0; i < n; ++i)cout << "1 ";
        return 0;
    }
    if(k == 1){
        cout << sum << endl;
        cout << n;
        return 0;
    }
    sort(p,p+n,cmp);
    int *ar = new int[k];
    for(int i = 0; i < k; ++i){
        ar[i] = p[i].second;
        sum+=p[i].first;
        
    }
    cout << sum << endl;
    sort(ar,ar+k);
    // if(ar[0] != 0)cout << ar[0]+1 << " ";
    // else cout << ar[1] << " ";
    // for(int i = 1; i < k-1; ++i){
    //     cout << ar[i]-ar[i-1] << " ";
    // }
    // cout << n-ar[k-1];
    int j = 0;
    int l = 0;
    int i;
    for(i = 0; i < n; ++i){
        if(j == k-1)break;
        if(i == ar[j]){
            cout << l+1 << " ";
            l = 0;++j;
        }else ++l;
    }
    for(; i < n; ++i){
        ++l;
    }
    cout << l;
    return 0;
}