#include<stdio.h>
#include<stdlib.h>
#define ll unsigned long long int
void build(ll *tree, ll *arr,int node, int start, int last){
    if(start == last)tree[node]=arr[start];
    else{
        int mid = start + (last-start)/2;
        build(tree,arr,2*node,start,mid);
        build(tree,arr,2*node+1,mid+1,last);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(ll *tree, int node, int start, int last, int L, int R){
    if(R < start || L > last)return 0;
    if(L<=start && R>=last)return tree[node];
    int mid = start + (last-start)/2;
    ll p1 = query(tree,2*node,start,mid,L,R);
    ll p2 = query(tree,2*node+1,mid+1,last,L,R);
    return p1+p2;
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    ll *arr = (ll*)malloc(sizeof(ll)*n);
    ll *comp_arr = (ll*)malloc(sizeof(ll)*n);
    int i;
    for(i = 0; i < n; ++i){
        scanf("%lld",&arr[i]);
        comp_arr[i] = (~arr[i]);
    }
    int k = n;
    int sum = 2;
    while(k){
        sum+=k;
        k/=2;
    }
    ll *tree = (ll*)calloc(sum+1,sizeof(ll));
    ll *comp_tree = (ll*)calloc(sum+1,sizeof(ll)*(k+1));
    build(tree,arr,1,1,n);
    build(comp_tree,comp_arr,1,1,n);
    while(q--){
        int l,r;
        printf("ENTER L AND R: ");
        scanf("%d%d",&l,&r);
        ll k = query(tree,1,1,n,l,r);
        ll comp_k = query(comp_tree,1,1,n,l,r);
        // ll x;
        ll max = 0;
        ll maxX = 0;
        ll x = (1<<31);
        for(i = 1; i < 33; ++i)
        {
            x = (1<<i);
            printf("%d\t%lld\n",i,x);
            ll z = ((x&comp_k)|((~x)&k));
            if(z > max){max = z;maxX=x;}
            if(z == max)maxX=x;
            if(z < max){
                while(x<(1<<(i+1))){
                    z = ((x&comp_k)|((~x)&k));
                    if(z > max){max = z;maxX=x;}
                    if(z == max)maxX=x;
                    x++;
                }
            }
        }
        printf("%lld\n",maxX);
    }
    return 0;
}