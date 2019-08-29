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
using namespace std;

V<int> v;
P<int,int> *pos;
struct node{
    int val;
    V<struct node*> child;
};

void setVector(struct node *root){
    v.pb(root->val);
    pos[root->val].first = v.size()-1;
    for(int i = 0; i < root->child.size(); ++i){
        setVector(root->child[i]);
        // v[root->val].insert(v[root->val].end(),v[root->child[i]->val].begin(),v[root->child[i]->val].end());
    }
    pos[root->val].second = v.size()-1;
}

int main(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    struct node* arr = new struct node[n+1];
    arr[1].val = 1;
    for(int i = 2; i <= n; ++i){
        int a;
        arr[i].val=i;
        cin >> a;
        arr[a].child.pb(arr+i);
    }
    pos = new P<int,int>[n+1];
    setVector(arr+1);
    while(q--){
        int u,k;
        cin >> u >> k;
        if((pos[u].second - pos[u].first + 1) < k){
            cout << "-1\n";
            continue;
        }
        cout << v[pos[u].first + k-1] << endl;
    }
    return 0;
}