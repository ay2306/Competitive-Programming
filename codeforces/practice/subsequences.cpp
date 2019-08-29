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

const ll maxn = 1e5 + 5;

ll tree[4*maxn][12], arr[maxn];

void build_segment_tree(ll node, ll start, ll last, ll len){
    if(start > last)return;
    if(start == last){
        for(ll i = 1; i <= len; ++i){
            tree[node][i] = 0;
        }
        return ;
    }
    ll mid = (start+last)/2;
    build_segment_tree(2*node, start, mid, len);
    build_segment_tree(2*node+1, mid+1, last, len);
    for(ll i = 1; i <= len; ++i){
        tree[node][i] = tree[2*node][i] + tree[2*node + 1][i];
    }
    return ;
}

void update_segment_tree(ll node,ll start, ll end, ll l, ll r, ll len, ll val){
    if(r < start || l > end)return;
    if(l<=start && r>=end){
        tree[node][len]+=val;
        return ;
    }
    update_segment_tree(2*node,start,(start+end)/2,l,r,len,val);
    update_segment_tree(2*node+1,(start+end)/2+1,end,l,r,len,val);
    tree[node][len] = tree[2*node][len] + tree[2*node + 1][len];
}

ll query_segment_tree(ll node, ll start, ll end, ll l, ll r, ll len){
    if(r < start || end < l)return 0;
    if(l <= start && end <= r)return tree[node][len];
    ll ans = query_segment_tree(2*node,start,(start+end)/2,l,r,len);
    ans += query_segment_tree(2*node+1,(start+end)/2+1,end,l,r,len);
    return ans;
}

int main(){
    ll n,len;
    cin >> n >> len;
    loop(i,1,n+1)cin >> arr[i];
    build_segment_tree(1,1,n,len);
    for(ll i = 1; i <= n; ++i){
        for(ll length = 0; length <= len; ++length){
            ll value = query_segment_tree(1,1,n,1,arr[i]-1,length);
            if(length == 0){
                value = 1;
            }
            update_segment_tree(1,1,n,arr[i],arr[i],length+1,value);
        }

    }
    cout << tree[1][len+1];
    return 0;
}