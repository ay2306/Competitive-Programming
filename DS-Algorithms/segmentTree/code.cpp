#include<bits/stdc++.h>
using namespace std;


vector<int> tree;
vector<int> arr;

void build(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*node +1, start,mid);
    build(2*node +2, mid+1, end);
    tree[node] = min(tree[2*node + 1],tree[2*node+2]);
}

void update(int node, int start, int end, int val, int ind){
    if(start == end){
        arr[ind] = val;
        tree[node] = arr[ind];
        return;
    }
    int mid = (start+end)/2;
    if(ind <= mid)update(2*node +1, start,mid, val, ind);
    else update(2*node +2, mid+1, end,val, ind);
    tree[node] = min(tree[2*node + 1],tree[2*node+2]);
}

int query(int node, int start, int end, int l, int r){
    if(start > r || end < l)return INT_MAX;
    if(start >= l && end <= r)return tree[node];
    int mid = (start + end)/2;
    return min(query(2*node + 1, start, mid, l,r),query(2*node + 2, mid + 1, end, l, r));
}

int main(){
    int n;
    cin >> n;
    tree = vector<int>(4*n);
    arr  = vector<int> (n);
    
}