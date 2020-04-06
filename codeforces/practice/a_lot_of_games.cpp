//https://codeforces.com/contest/455/problem/B
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

struct node{
    char c;
    int dep;
    bool win;
    unordered_map<char,node*> children;
};

class trie{
public:
    node *parent;
    trie(){
        parent = new node();
        parent->dep = 0;
    }
    void add(string &a){
        node *current = parent;
        for(int j = 0; j < a.size(); ++j){
            char i = a[j];
            if(current->children.find(i) == current->children.end()){
                current->children[i] = new node();
            }
            current = current->children[i];
            current->dep = j+1;
            current->c = a[j];
        }
    }
    bool exists(string &a)const{
        node *current = parent;
        for(auto &i: a){
            if(current->children.find(i) == current->children.end()){
                return false;
            }
            current = current->children[i];
        }
        return true;
    }
    int dfs(node *current){
        unordered_map<int,int> m; 
        if(current->children.size() == 0){
            cout << "LEAF " << nodeName(current) << " return " << current->dep%2 << "\n";
            return ((current->dep%2));
        }
        for(auto &i: current->children){
            int a = dfs(i.second);
            m[a]++;
        }
        if(m.size() == 2){
            if(current->dep%2){
                cout << nodeName(current) << " return 0\n";
                return 0;
            }
            cout << nodeName(current) << " return 1\n";
            return 1;
        }
        else if(m.begin()->first == 1){
            cout << nodeName(current) << " return 1\n";
            return 1;
        }
        cout << nodeName(current) << " return 0\n";
        return 0;
    }   
    string nodeName(node *a){
        if(a == parent)return "ROOT";
        return string(1,a->c);
    }
};

int main(){
    FAST;
    trie *a = new trie();
    int n,k;
    cin >> n >> k;
    string b;
    while(n--){
        cin >> b;
        a->add(b);
    }
    n = a->dfs(a->parent);
    if(n == 1){
        cout << "First";
    }else{
        cout << "Second";
    }
   return 0;
}