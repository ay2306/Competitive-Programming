//******************************************************************************
//Problem: How many vertices in a subtree of vertex v are colored with color c *
//Method: Disjoint Set Union on trees                                          *
//Date: July 16 2018                                                           *
//                                                                             *
//                                                                             *
//                                                                             *
//                                                                             *
//                                                                             *
//                                                                             *
//                                                                             *
//******************************************************************************

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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

class tree{
    int v;
    char *col;
    V<int> *g;
    int *sz; //Holds 
public:
    tree(int v){
        this->v = v;
        this->g = new V<int>[v+1];
        this->col = new char[v+1];
        this->sz = new int[v+1];
    }
    void setColor(int a, char b){
        col[a] = b;
    }
    void edge(int a,int b){
        g[a].pb(b);
    }
    void getsz(){
        
    }
}

int main(){
    //Step 1 make a tree (common sense)
    
    return 0;
}