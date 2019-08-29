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

ll maxi(ll a, ll b){
    if(a>b)return a;
    return b;
}
int main(){
    ull n[3],p[3],r,arr[3]={0};
    ull c=0;
    string a;
    cin >> a;   
    for(int i = 0; i < a.length(); ++i){
        if(a[i] == 'B')arr[0]++;
        if(a[i] == 'S')arr[1]++;
        if(a[i] == 'C')arr[2]++;
    }
    for(int i = 0; i < 3; ++i)cin >> n[i];
    for(int i = 0; i < 3; ++i)cin >> p[i];
    cin >> r;
    ull high = LLONG_MAX;
    ull low = 0;
    ull LA = 0;
    ull mid;
    while(low < high){
        mid = low + (high - low )/2;
        ll cost = 0;
        for(int i = 0; i < 3; ++i){
            cost+= maxi(0,(arr[i]*mid - n[i]))*p[i];
        }
        // cout << r << " " << cost  << "  " << mid << endl;
        if(cost > r){
            // cout << "CASE 1\n";
            high = mid-1;
        }
        if(cost < r){
            // cout << "CASE 2\n";
            if(LA < mid)LA=mid;
            low = mid+1;
        }
        if(cost == r){
            // cout << "CASE 3\n";
            if(LA < mid)LA=mid;
            break;
        }
    }
    cout << mid;
    return 0;
}

/*
BBBSSC
6 4 1
1 2 3
4

SSSSSSSSSSBBBBBBBBBCCCCCCCCCCCCCCCCCCCSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSBB
31 53 97
13 17 31
914159265358

*/