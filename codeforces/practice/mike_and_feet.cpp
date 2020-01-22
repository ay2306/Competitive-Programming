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
V<int> tree;
V<int> lazy;
int n;

void update(int l, int r, int val, int node = 0, int start = 0, int end = n){
    if(lazy[node]){
        tree[node] = max(lazy[node],tree[node]);
        if(start != end){
            lazy[(node << 1)+1]=max(lazy[node],lazy[(node << 1)+1]);
            lazy[(node << 1)+2]=max(lazy[node],lazy[(node << 1)+2]);
        }
    }
    if(l > end || r < start )return;
    if(l <= start && end <= r){
        tree[node] = max(val,tree[node]);
        if(start != end){
            lazy[(node << 1)+1]=max(val,lazy[(node << 1)+1]);
            lazy[(node << 1)+2]=max(val,lazy[(node << 1)+2]);
        }
        return;
    }
    update(l,r,val,node*2+1,start,(start+end)/2);
    update(l,r,val,node*2+2,(start+end)/2+1,end);
}

int query(int l, int r, int node = 0, int start = 0, int end = n){
    if(lazy[node]){
        tree[node] = max(lazy[node],tree[node]);
        if(start != end){
            lazy[(node << 1)+1]=max(lazy[node],lazy[(node << 1)+1]);
            lazy[(node << 1)+2]=max(lazy[node],lazy[(node << 1)+2]);
        }
    }
    if(l > end || r < start )return 0;
    if(l <= start && end <= r){
        return tree[node];
    }
    int p1 = query(l,r,node*2+1,start,(start+end)/2);
    int p2 = query(l,r,node*2+2,(start+end)/2+1,end);
    return max(p1,p2);
}

int main(){
    cin >> n;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    V<int> lower(n,-1);
    V<int> lower1(n,-1);
    stack<int> s;
    tree = V<int> (4*n+4,0);
    lazy = V<int> (4*n+4,0);
    loop(i,0,n){
        while(s.size() && arr[s.top()] > arr[i]){
            lower[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(s.size())s.pop();
    loopr(i,n-1,0){
        while(s.size() && arr[s.top()] > arr[i]){
            lower1[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    loop(i,0,n){
        int l = 0;
        if(lower[i] == -1)l=n-i;
        else l = lower[i]-i;
        l+=(i-lower1[i]);
        l--;
        // printf("i = %d, arr[i] = %d, lower[i] = %d, lower1[i] = %d, l = %d\n",i,arr[i],lower[i],lower1[i],l);
        update(1,l,arr[i]);
    }
    loop(i,1,n+1)cout << query(i,i) << " ";
    return 0;
}