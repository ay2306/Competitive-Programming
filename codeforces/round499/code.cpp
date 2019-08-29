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

struct vertex
{
    char type;
    vector<int>in;
    bool val;
    bool change;
};

int n;
vector<vertex> g;

int dfs1(int v)
{
    switch(g[v].type)
    {
    case 'A':
        g[v].val = dfs1(g[v].in[0]) & dfs1(g[v].in[1]);
        break;
    case 'O':
        g[v].val = dfs1(g[v].in[0]) | dfs1(g[v].in[1]);
        break;
    case 'X':
        g[v].val = dfs1(g[v].in[0]) ^ dfs1(g[v].in[1]);
        break;
    case 'N':
        g[v].val = ! dfs1(g[v].in[0]);
        break;
    }
    return g[v].val;
}

void dfs2(int v)
{
    if(g[v].change==false)
        for(int i=0;i<g[v].in.size();i++)
            g[g[v].in[i]].change=false;
    else
        switch(g[v].type)
        {
        case 'A':
            if(g[v].val==(!g[g[v].in[0]].val&g[g[v].in[1]].val)){ 
                g[g[v].in[0]].change=false;
            }
            else{
                g[g[v].in[0]].change=true;
            }
            if(g[v].val==(g[g[v].in[0]].val&!g[g[v].in[1]].val)){
                g[g[v].in[1]].change=false;
            }
            else{
                g[g[v].in[1]].change=true;
            }
            break;
        case 'O':
            if(g[v].val==(!g[g[v].in[0]].val|g[g[v].in[1]].val)) /// equal to if(g[g[v].in[1]].val==true)
                g[g[v].in[0]].change=false;
            else
                g[g[v].in[0]].change=true;
            if(g[v].val==(g[g[v].in[0]].val|!g[g[v].in[1]].val)) /// equal to if(g[g[v].in[0]].val==true)
                g[g[v].in[1]].change=false;
            else
            break;
                g[g[v].in[1]].change=true;
        case 'X':
            if(g[v].val==(!g[g[v].in[0]].val^g[g[v].in[1]].val)) /// equal to if(false)
                g[g[v].in[0]].change=false;
            else
                g[g[v].in[0]].change=true;
            if(g[v].val==(g[g[v].in[0]].val^!g[g[v].in[1]].val)) /// equal to if(false)
                g[g[v].in[1]].change=false;
            else
                g[g[v].in[1]].change=true;
            break;
        case 'N':
            if(g[v].val==(!!g[g[v].in[0]].val)) /// equal to if(false)
                g[g[v].in[0]].change=false;
            else
                g[g[v].in[0]].change=true;
            break;
        }
    for(int i=0;i<g[v].in.size();i++)
        dfs2(g[v].in[i]);
}

int main()
{
    scanf("%d",&n);
    g.resize(n);
    for(int i=0;i<n;i++)
    {
        char c[4];
        scanf("%s",c);
        g[i].type=c[0];
        int x;
        switch(g[i].type)
        {
        case 'I':
            scanf("%d",&x);
            g[i].val=x;
            break;
        case 'N':
            scanf("%d",&x);
            g[i].in.push_back(x-1);
            break;
        default:
            scanf("%d",&x);
            g[i].in.push_back(x-1);
            scanf("%d",&x);
            g[i].in.push_back(x-1);
            break;
        }
    }
    dfs1(0);
    g[0].change=true;
    dfs2(0);
    for(int i=0;i<n;i++)
        if(g[i].type=='I')
            printf("%d",g[0].val^g[i].change);
}