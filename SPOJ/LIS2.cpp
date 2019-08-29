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
#define MAXN 25
using namespace std;


struct Element{
    int x,y,i;
    bool operator <(const Element& rhs){
        // if(x < rhs.x && y < rhs.y)return true;
        if(y < rhs.y)return true;
        
        return false;
    }
    bool operator >(const Element& rhs){
        // if(x > rhs.x && y > rhs.y)return true;
        if(y > rhs.y)return true;
        return false;
    }
};
bool cmp(Element a, Element b){
    if(a.x < b.x)return true;
    if(a.x > b.x)return false;
    if(b.y < a.y)return true;
    if(b.y > a.y)return false;
    return (a.i > b.i);
}

void solve(){
    int n;
    cin >> n;
    Element *arr = new Element[n];
    loop(i,0,n){
        int x,y;
        cin >> x >> y;
        arr[i].x = x;
        arr[i].y = y;
        arr[i].i = i;
    }
    sort(arr,arr+n,cmp);
    loop(i,0,n){
        printf("(%d, %d)\n",arr[i].x,arr[i].y);
    }
    V<Element> q;
    for(int i = 0; i < n; ++i){
        int index = lower_bound(q.begin(),q.end(),arr[i])-q.begin();
        // int index;
        // for(index = 0; index < q.size() && q[index] < arr[i]; index++);
        if(index == q.size())q.pb(arr[i]);
        else q[index] = arr[i];
    }
    V<int> q1;
    V<int> arr1;
    cout << "Q: \n";
    loop(i,0,q.size()){
        printf("(%d, %d, %d)\n",q[i].x,q[i].y,q[i].i);
        arr1.pb(q[i].i);
    }
    for(int i = 0; i < q.size(); ++i){
        int index = lower_bound(q1.begin(),q1.end(),arr1[i])-q1.begin();
        if(index == q1.size())q1.pb(arr1[i]);
        else q1[index] = arr1[i];
    }

    cout << q1.size();
}

int main(){
    FILE_READ_IN
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}