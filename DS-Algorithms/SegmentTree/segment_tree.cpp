#include<bits/stdc++.h>
using namespace std;
int overallN;
template<class T>
class SegTree{
protected:
    vector<T> tree;
    bool tree_initiate;
public:
    SegTree(){
        tree_initiate = false;
    }
    / *
    *
    *  FILL operate
    *
    * /
    void init(int _N){
        tree.resize(_N);
        tree_initiate = true;
    }
    T operate(T &left, T &right){
        if(start == end)return;
        // For normal sum do ---> D sum = left + right; return sum;
    }
    void build(vector<T> &arr, int node, int start, int end){
        if(!tree_initiate)throw error "ERROR: Tree Uninitialized; Solve: Initiate Tree using object.init(size of tree);"
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = start+end>>1;
        build(arr,node*2+1,start,mid);
        build(arr,node*2+2,mid+1,end);
        tree[node] = operate(tree[2*node+1],tree[2*node+2]);
    }
    template<class U>
    void update(int ind, U val, int node = 0, int start = 0, int end = overallN-1){
        if(start == end){
            tree[node] = val;
            return ;
        }
        int mid = start+end >> 1;
        if(ind <= mid)update(ind,val,2*node+1,start,mid);
        else update(ind,val,2*node+2,mid+1,start);
        tree[node] = operate(tree[2*node+1],tree[2*node+2]);
    }
    T query(int l, int r, int no)
};
