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
// using namespace std;

std::V<int> parent;
std::V<int> rank;
// V<PII> arr;

int getParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void UNION(int a,int b){
    int pa = getParent(a);
    int pb = getParent(b);
    if(rank[pb] < rank[pa]){
        parent[pb] = pa; 
    }
    else if(rank[pb] > rank[pa]){
        parent[pa] = pb; 
    }else{
        parent[pb] = pa;
        rank[pa]++;
    }
}

int main(){
    int n,m;
    std::cin >> n >> m;
    parent = std::V<int>(n+1,0);
    loop(i,1,n+1)parent[i] = i;
    rank = std::V<int>(n+1,0);
    while(m--){
        int a,b;
        std::cin >> a >> b;
        UNION(a,b);
    }
    std::V<int> arr(n+1);
    loop(i,1,n+1)std::cin >> arr[i];
    std::unordered_map<int,int> MP;
    for(int i = 1; i <= n; ++i){
        int p = getParent(i);
        if(MP.find(p) == MP.end()){
            MP[p] = arr[i];
        }else if(MP[p] < 0 && arr[i] >= 0){
            MP[p] = arr[i];
        }else if(arr[i] >= 0){
            MP[p] = std::min(MP[p],arr[i]);
        }
    }
    std::V<int> ans;
    for(auto i: MP){
        ans.pb(i.second);
        // cout << i.F << " " << i.S << "\n";
    }
    std::sort(ans.begin(),ans.end());
    if(ans.size() == 1){
        std::cout << "0";
        return 0;
    }
    if(ans[0] < 0){
        std::cout << "-1";
        return 0;
    }
    int s = 0;
    for(int i = 1; i < ans.size(); ++i)s+=(ans[i] + ans[0]);
    std::cout << s;
    return 0;
}