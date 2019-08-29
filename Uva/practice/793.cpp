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
#define MAXN 1001000
using namespace std;
class solution{
V<int> parent;
V<int> rank;
public:
    solution(int n){
        parent = V<int> (n,0);
        rank = V<int> (n,0);
        for(int i = 1; i < n; ++i)parent[i] = i;
    }
    void UNION(int x, int y){
        int px = findParent(x);
        int py = findParent(y);
        if(rank[px] > rank[py]){
            parent[py] = parent[px];
        }
        else if(rank[px] < rank[py]){
            parent[px] = parent[py];
        }
        else{
            parent[px] = parent[py];
            rank[px]++;
        }
    }
    int findParent(int x){
        while(x != parent[x]){
            x = parent[x];
        }
        return x;
    }
};

int main(){
    // FILE_READ
    int t;
    cin >> t;
    int n;
    string a;
    int kapa = 0;
    while(t--){
        int suc = 0;
        do{
            getline(cin,a);
        }while(a == "");
        stringstream p(a);
        p >> n;
        if(kapa++){
            cout << "\n";
        }
        // cout << n;
        int fail = 0;
        solution s(n);
        getline(cin,a);
        while(1){
            if(a == "")break;
            stringstream ss(a);
            if(a[0] != 'q' && a[0]!='c'){
                ss >> n;
                break;
            }
            int b,c;
            char q;
            ss >> q >> b >> c;
            if(q == 'c'){
                s.UNION(b-1,c-1);
            }else{
                if(s.findParent(b-1) == s.findParent(c-1)){
                    suc++;    
                }
                else fail++;
            }
            getline(cin,a);
        }
        printf("%d,%d\n",suc,fail);
    }
    return 0;
}