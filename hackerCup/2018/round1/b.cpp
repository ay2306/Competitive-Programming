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

class Tree{
    struct node{
        ll L;
        struct node* left;
        struct node* right;
    };
    struct node** root;
    V<ll> POD;
    V<ll> PSD;
    int n;
public:
    Tree(int n){
        root = new struct node*[n+1];
        for(int i = 1; i <= n; ++i){
            ll a,b;
            cin >> a >> b;
            root[i]->L = LLONG_MAX - 1LL*23*INT_MAX;
            if(a!=0)root[i]->left = (root[a]);
            else root[i]->left = NULL;
            if(b!=0)root[i]->right = (root[b]);
            else root[i]->right = NULL;
            // if(root[i].L )
        }
        preorder(*root);
        cout << endl;
        inorder(*root);
        cout << endl;
        for(int i = 0; i < POD.size(); ++i){
            if(POD[i] == LLONG_MAX - 1LL*23*INT_MAX)cout << "U";
            else cout << POD[i];
            cout << " ";
        }
        cout << endl;
        for(int i = 0; i < PSD.size(); ++i){
            if(PSD[i] == LLONG_MAX - 1LL*23*INT_MAX)cout << "U";
            else cout << PSD[i];
            cout << " ";
        }
        cout << endl;
    }
    void preorder(struct node* ptr){
        if(ptr == NULL)return;
        cout << "POD";
        POD.pb(ptr->L);
        preorder(ptr->left);
        preorder(ptr->right);
    }

    void inorder(struct node* ptr){
        if(ptr == NULL)return;
        cout << "PSD";
        inorder(ptr->left);
        inorder(ptr->right);
        PSD.pb(ptr->L);
    }
};

int main(){
    FILE_READ
    int t;
    cin >> t;
    cout << "TEST 2" << endl;
    for(int l = 1; l <= t; ++l){
        int n,k;
        cin >> n >> k;
        cout << "CASE #" << l << " : " << endl;
        Tree T(n);
    }
    return 0;
}

void bfs(int node, int k, int lev){
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); ++i){
        if(!visited[adj[node][i]]){
            
        }
    }
}