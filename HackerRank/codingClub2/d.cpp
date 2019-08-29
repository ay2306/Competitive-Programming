#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void buildTree(ll *tree, ll node, ll *arr, ll start, ll end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    ll mid = (start + end)/2;
    buildTree(tree,2*node+1,arr,start,mid);
    buildTree(tree,2*node+2,arr,mid+1,end);
    tree[node] = (tree[2*node+1]^tree[2*node+2]);
}

void update(ll *tree, ll node, ll start, ll end, ll val, ll index){
    if(index < start || index > end)return;
    if(start == end){
        tree[node] = val;
        return;
    }
    ll mid = (start+end)/2;
    update(tree,2*node+1,start,mid,val,index);
    update(tree,2*node+2,mid+1,end,val,index);
    tree[node] = (tree[2*node+1]^tree[2*node+2]);
}

void display(ll *tree, ll node, ll start, ll end){
    if(start == end){
        cout << tree[node] << " ";
        return;
    }
    ll mid = (start+end)/2;
    display(tree,2*node+1,start,mid);
    display(tree,2*node+2,mid+1,end);
}


ll query(ll *tree, ll node, ll start, ll end, ll l, ll r){
    if(l > end || r < start)return 0;
    if(l <= start && r >= end)return tree[node];
    ll mid = (start+end)/2;
    ll left_result = query(tree,2*node+1,start,mid,l,r);
    ll right_result = query(tree,2*node+2,mid+1,end,l,r);
    return (left_result^right_result);
}

int main(){
    ll n,q;
    cin >> n >> q;
    ll *arr = new ll[n+1];
    ll *arr1 = new ll[n+1];
    ll *arr2 = new ll[n+1];
    for(int i = 0; i <  n; ++i){
        cin >> arr[i];
        if(i%2 == 0)arr1[i] = arr[i];
        else arr1[i]=0;
        if(i%2 == 1)arr2[i] = arr[i];
        else arr2[i]=0;
    }
    ll *tree1 = new ll[4*n + 1];
    buildTree(tree1,0,arr1,0,n-1);
    ll *tree2 = new ll[4*n + 1];
    buildTree(tree2,0,arr2,0,n-1);
    
    while(q--){
        char a;
        ll b,c;
        cin >> a >> b >> c;
        if(a == 'u'){
            b--;
            if(b%2 == 0){
                update(tree1,0,0,n-1,c,b);
                // display(tree1,0,0,n-1);
            }else{
                update(tree2,0,0,n-1,c,b);
                // display(tree2,0,0,n-1);
            }
        }else{
            b--;c--;
            if((c-b)%2 == 1){
                cout << "0\n";
            }else{
                if(b%2 == 0){
                    cout << query(tree1,0,0,n-1,b,c) << endl;
                }
                if(b%2 == 1){
                    cout << query(tree2,0,0,n-1,b,c) << endl;
                }
            }
        }
    }
    return 0;
}