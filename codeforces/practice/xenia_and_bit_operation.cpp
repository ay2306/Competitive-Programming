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

const int N = (1LL << 17);
int arr[N];
int tree[4*N];
int n,m;
void build(int node = 0, int start = 0, int end = (1<<n)-1){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    build(2*node+1, start, (start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    if(int(log2(end-start+1))%2 == 1){
        tree[node] = tree[2*node+1]|tree[2*node+2];
    }else{
        tree[node] = tree[2*node+1]^tree[2*node+2];
    }
}

void update(int index, int val, int node = 0, int start = 0, int end = (1<<n)-1){
    if(index > end || index < start)return;
    if(start == end){
        tree[node] = val;
        arr[start] = val;
        return;
    }
    update(index,val,2*node+1,start,(start+end)/2);
    update(index,val,2*node+2,(start+end)/2+1,end);
    if(int(log2(end-start+1))%2 == 1){
        tree[node] = tree[2*node+1]|tree[2*node+2];
    }else{
        tree[node] = tree[2*node+1]^tree[2*node+2];
    }
}

int main(){
    scanf("%d %d",&n,&m);
    loop(i,0,(1<<n)){
        scanf("%d",arr+i);
    }
    build();
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        update(a-1,b);
        printf("%d\n",tree[0]);
    }
    return 0;
}