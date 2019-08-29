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
using namespace std;

const ll maxn = 1e5;
int n;
V<int> min_tree;
V<int> max_tree;
V<int> arr;

void build(int node = 0, int start = 0, int last = n-1){
    if(start == last){
        min_tree[node] = start;
        max_tree[node] = start;
        return;
    }
    int mid = (start + last)/2;
    build(2*node + 1, start, mid);
    build(2*node + 2, mid+1, last);
    min_tree[node] = (arr[min_tree[2*node + 1]] < arr[min_tree[2*node+2]])?min_tree[2*node+1]:min_tree[2*node+2];
    max_tree[node] = (arr[max_tree[2*node + 1]] > arr[max_tree[2*node+2]])?max_tree[2*node+1]:max_tree[2*node+2];
}

PII query(int l, int r, int node = 0, int start = 0, int last = n-1){
    if(start > r || last < l)return mp(n+1,n+1);
    if(start >= l && last <= r )return mp(min_tree[node],max_tree[node]);
    int mid = (start+last)/2;
    auto p1 = query(l,r,2*node+1,start,mid);
    auto p2 = query(l,r,2*node+2,mid+1,last);
    PII ans;
    if(p1.first == n+1){
        ans.first = p2.first;
    }
    if(p2.first == n+1){
        ans.first = p1.first;
    }
    if(p1.second == n+1){
        ans.S = p2.S;
    }
    if(p2.S == n+1){
        ans.S = p1.S;
    }
    if(p1.F != n+1 && p2.F != n+1){
        ans.F = (arr[p1.F] < arr[p2.F])?p1.F:p2.F;
    }
    if(p1.S != n+1 && p2.S != n+1){
        ans.S = (arr[p1.S] > arr[p2.S])?p1.S:p2.S;
    }
    return ans;
}

int main(){
    FAST
    int m;
    cin >> n >> m;
    min_tree = V<int> (4*n);
    max_tree = V<int> (4*n);
    arr = V<int> (n);
    loop(i,0,n){
        cin >> arr[i];
    }
    build();
    // for(auto i: min_tree){
    //     cout << i << " ";
    // }
    // cout << endl;
    // for(auto i: max_tree){
    //     cout << i << " ";
    // }
    // cout << endl;
    while(m--){
        int l,r,x;
        cin >> l >> r >> x;
        l--;
        r--;
        auto a = query(l,r);
        // printf("( %d, %d )\n",a.first,a.second);
        if(arr[a.first] == x && arr[a.second] == x)cout << "-1\n";
        else if(arr[a.first] != x)cout << a.first+1 << "\n";
        else if(arr[a.second] != x)cout << a.second+1 << "\n";
    }
    return 0;
}