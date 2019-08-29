#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Trie{
    Trie *left,*right;  
    Trie(){
        left=right=NULL;
    }
}*base;
    Trie* newNode(){
        Trie* ptr = new Trie;
        ptr->a = 0;
        ptr->arr[0] = NULL;
        ptr->arr[1] = NULL;
        return ptr;
    }
    void insert(Trie* root, ll pre_xor){
        Trie* ptr = root;
        for(int i = 64 - 1; i >= 0; i--){
            bool val = pre_xor & (1LL << i);
            if(ptr->arr[val] == NULL)ptr->arr[val] = newNode();
            ptr = ptr->arr[val];
        }
        ptr->a = pre_xor;
    }
    ll query(Trie *root, ll pre_xor){
        Trie *ptr = root;
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
        Trie *root = newNode();
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