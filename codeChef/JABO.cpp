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

//WUPC : Weighted Union with class compression
class WUPC{
    private:
        V<int> parent;
        V<int> size;
        V<int> sources;
        int root(int a);
    public:
        WUPC(int s){
            parent = V<int>(s+1);
            size = V<int>(s+1,0);
            sources = V<int>(s+1,0);
            auto it = parent.begin();
            for(int i = 0; it != parent.end(); ++it, ++i){
                *it = i;
            }
        }
        void join(int a, int b);
        bool getPotential(int a){
            int ns = sources[root(a)];
            assert(ns >= 0);
            return ns != 0;
        }
        void setPotential(int a){
            sources[root(a)]++;
        }
        void unsetPotential(int a){
            sources[root(a)]--;
        }
};
void WUPC::join(int a, int b){
    int rootA = root(a);
    int rootB = root(b);
    if(rootA != rootB){
        if(size[rootA] < size[rootB]){
            parent[rootA] = rootB;
            size[rootB]+=size[rootA];
            sources[rootB] += sources[rootA];
        }else{
            parent[rootB] = rootA;
            size[rootA]+=size[rootB];
            sources[rootA] += sources[rootB];
        }
    }
}

int WUPC::root(int a){
    while(a != parent[a]){
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

inline int coor_to_num(int x, int y, int c){
    return ((y-1)/5)*c + x - 1;
}

int dec(char a, char b){
    int r = 0;
    if(a & 32)r+=(a-'a'+26);
    else r+=(a-'A');
    r*=52;
    if(b & 32)r+=(b-'a'+26);
    else r+=(b-'A');
    return r;
}

void solve(){
    int n,r,c, x1,x2,y1,y2;
    cin >> n >> r >> c;
    WUPC wupc(c*r);
    while(n--){
        string a;
        cin >> a;
        switch(a[0]){
            case 'W':
                x1 = dec(a[1],a[2]);
                y1 = dec(a[3],a[4]);
                x2 = dec(a[5],a[6]);
                y2 = dec(a[7],a[8]);
                wupc.join(coor_to_num(x1,y1,c),coor_to_num(x2,y2,c));
                break;
            
            case 'V':
                x1 = dec(a[1],a[2]);
                y1 = dec(a[3],a[4]);
                wupc.setPotential(coor_to_num(x1,y1,c));
                break;
            
            case 'R':
                x1 = dec(a[1],a[2]);
                y1 = dec(a[3],a[4]);
                wupc.unsetPotential(coor_to_num(x1,y1,c));
                break;
            
            case 'L':
                x1 = dec(a[1],a[2]);
                y1 = dec(a[3],a[4]);
                x2 = dec(a[5],a[6]);
                y2 = dec(a[7],a[8]);
                int p1 = coor_to_num(x1,y1,c);
                int p2 = coor_to_num(x2,y2,c);
                if(wupc.getPotential(p1) != wupc.getPotential(p2)){
                    printf("ON\n");
                }else{
                    printf("OFF\n");
                }
                break;
            
        }
    }
}

int main(){
    FAST
    // FILE_READ_IN
    int t = 1;
    while(t--)solve();
    return 0;
}