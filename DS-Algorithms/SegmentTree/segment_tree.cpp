#include<bits/stdc++.h>
using namespace std;
int overallN;
template<class T>
class SegTree{
protected:
    vector<T> tree;
public:
    SegTree(vector<T> &arr){
        tree.resize(arr.size()<<2);
        build(arr,0,0,tree.size()-1);
        overallN = tree.size();
    }
    SegTree(int N){
        tree.resize(N<<2);
        overallN = N;
    }
    / *
    *
    *  FILL operate
    *
    * /
    void operate(int node, int start, int end){
        if(start == end)return;
    }
    template<class U>
    void UpdateOperate(int node, U val){

    }
    void build(vector<T> &arr, int node, int start, int end){
        if(start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = start+end>>1;
        build(arr,node*2+zero,start,mid);
        build(arr,node*2+1+zero,mid+1,end);
        operate(node,start,end);
    }
    template<class U>
    void update(int ind, U val, int node = 0, int start = 0, int end = overallN-1){
        if(start == end){
            UpdateOperate()
        }
    }
};
