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



class Trie{
struct TrieNode{
    ll a;
    TrieNode* arr[2];
};
public:
    TrieNode* newNode(){
        TrieNode* ptr = new TrieNode;
        ptr->a = 0;
        ptr->arr[0] = NULL;
        ptr->arr[1] = NULL;
        return ptr;
    }
    void insert(TrieNode* root, ll pre_xor){
        TrieNode* ptr = root;
        for(int i = 64 - 1; i >= 0; i--){
            bool val = pre_xor & (1LL << i);
            if(ptr->arr[val] == NULL)ptr->arr[val] = newNode();
            ptr = ptr->arr[val];
        }
        ptr->a = pre_xor;
    }
    ll query(TrieNode *root, ll pre_xor){
        TrieNode *ptr = root;
        for(int i = 64 - 1; i >= 0; --i){
            bool val = pre_xor & (1LL << i);
            if(ptr->arr[1-val] != NULL){
                ptr = ptr->arr[1-val];
            }else if(ptr->arr[val] != NULL){
                ptr = ptr->arr[val];
            }
        }
        return (pre_xor^(ptr->a));
    }
    ll maxSubArrayXor(vector<ll> arr){
        int n = arr.size();
        TrieNode *root = newNode();
        insert(root,0);
        ll result = INT_MIN;
        ll pre_xor = 0;
        for(int i = 0; i < n; ++i){
            pre_xor^=arr[i];
            insert(root,pre_xor);
            result = max(result,query(root,pre_xor));
        }
        return result;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    Trie t;
    cout << t.maxSubArrayXor(arr) << "\n";
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}