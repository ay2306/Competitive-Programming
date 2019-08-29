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
#define PDD pair<double, double>
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
V<P<double,double> > arr;
bool comp(PDD a, PDD b){
    if(a.first < b.first)return true;
    if(a.first > b.first)return false;
    if(a.second > b.second)return false;
    return true;
}
double distance(int x1, int y1, int x2, int y2){
    double a = x1-x2;
    double b = y1-y2;
    return sqrt((a*a)+(b*b));
}
void InsertInfo(P<P<int,int>,int> a, P<P<int,int>,int> b){
    double CC = distance(a.first.first,a.first.second,b.first.first,b.first.second);// - a.second - b.second;
    double minDis = 0;// - a.second - b.second;
    double maxDis = 0;
    double r1 = a.second;
    double r2 = b.second;
    if(CC > r1+r2){
        minDis = CC - (r1 + r2);
        maxDis = CC + (r1 + r2);
        arr.push_back(mp(minDis,maxDis));
        // cout << "A1\n";
        return;
    }
    if(CC = r1+r2){
        minDis = 0;
        maxDis = 2*(r1+r2);
        arr.push_back(mp(minDis,maxDis));
        // cout << "A2\n";
        return;
    }
    if(CC < r1+r2 && abs(r1-r2) < CC){
        minDis = 0;
        maxDis = 2*max(r1,r2);
        arr.push_back(mp(minDis,maxDis));
        // cout << "A3\n";
        return;
    }
    if(CC < abs(r1-r2)){
        minDis = min(r1,r2)+CC;
        maxDis = CC + r1 + r2;
        arr.push_back(mp(minDis,maxDis));
        // cout << "A4\n";
        return;
    }
}

int findLMatch(double x){
    int l = 0;
    int low = 0;
    int high = arr.size()-1;
    int ans = INT_MAX;
    while(low <= high){
        // if(l++ > 1000)return -1;
        // cout << low << " " << high << endl;
        int mid = (low+high)/2;
        // cout << arr[mid].first << " " << arr[mid].second << " x  = " << x << endl; 
        if(arr[mid].first <= x && arr[mid].second >= x){high = mid-1; ans = min(ans,mid);}
        else if(arr[mid].first > x)high = mid-1;
        else low = mid+1;
    }
    // cout << ans << "\n";
    if(ans != INT_MAX)return ans;
    // if(arr[low].first <= x && arr[low].second >= x)return low;
    return -1;
}
int findRMatch(double x){
    int l = 0;
    int low = 0;
    int high = arr.size()-1;
    int ans = INT_MIN;
    while(low <= high){
        int mid = (low+high)/2;
        // cout << arr[mid].first << " " << arr[mid].second << " x  = " << x << endl; 
        if(arr[mid].first <= x && arr[mid].second >= x){low = mid+1;ans = max(mid,ans);}
        else if(arr[mid].first > x)high = mid-1;
        else low = mid+1;
    }
    // cout << ans << "\n";
    if(ans != INT_MIN)return ans;
    return -1;
}

int main(){
    FAST
    // FILE_READ
    // freopen("input.txt","r",stdin);
    int n,q;
    cin >> n >> q;
    P<P<int,int>, int>  *cinfo = new P<P<int,int>,int> [n];
    for(int i = 0; i < n; ++i){
        int x,y,r;
        cin >> x >> y >> r;
        cinfo[i] = mp(mp(x,y),r);
    }
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            InsertInfo(cinfo[i],cinfo[j]);
        }
    }
    sort(arr.begin(),arr.end(),comp);
    // for(auto i: arr){
    //     cout << "( " << i.first << ", " << i.second << " )\n";
    // }
    while(q--){
        double k;
        cin >> k;
        // int l = findLMatch(k);
        // int r = findRMatch(k);  
        // // cout << l << " " << r << "\n";
        // if(l == -1 || r == -1)cout << "0\n";
        // else cout << r-l+1 << "\n";
        int cnt = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i].first <= k && arr[i].second >= k){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}