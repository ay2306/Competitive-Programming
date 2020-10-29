#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,q;
int32_t main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&q);
        vector<int> tree(n*4),quality(n),quant(n);
        for(int &i: quality)scanf("%lld",&i);
        for(int &i: quant)scanf("%lld",&i);
        function<void(int,int,int)> build = [&](int node, int start, int end )->void{
            if(start == end){
                tree[node] = start;
                return;
            }
            int mid = (start + end)/2;
            build(node*2+1,start,mid);
            build(node*2+2,mid+1,end);
            int left = tree[2*node+1];
            int right = tree[2*node+2];
            if(quality[left] > quality[right])tree[node] = tree[2*node+1];
            else tree[node] = tree[node*2 + 2];
        };
        build(0,0,n-1);
        function<int(int,int,int,int,int)> query = [&](int l, int r, int node, int start, int end)->int{
            if(l > end || r < start)return -1;
            if(l <= start && end <= r)return tree[node];
            int mid = (start + end)/2;
            int left = query(l,r,node*2+1,start,mid);
            int right = query(l,r,node*2+2,mid+1,end);
            if(left == -1)return right;
            if(right == -1)return left;
            if(quality[left] > quality[right])return left;
            return right;
        };
        while(q--){
            int a,b,c,d;
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            if(a == 1){
                int index = query(b-1,c-1,0,0,n-1);
                quant[index]+=d;
            }else{
                int thres;
                scanf("%lld",&thres);
                int l = max(0LL,c-b-1);
                int r = min(n-1,c+b-1);
                int index = query(l,r,0,0,n-1);
                if(quant[index] < d || thres > quality[index])printf("No purchase\n");
                else {
                    printf("%lld\n",index+1);
                    quant[index]-=d;
                }
            }
        }
    }
    return 0;
}