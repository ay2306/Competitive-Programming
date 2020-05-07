#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int logs[N];
struct Sparse{
    int table[N][20];
    static void compute(){
        logs[1] = 0;
        for(int i = 2; i < N; ++i)logs[i]=logs[i/2]+1;
    }
    Sparse(vector<int> &arr){
        int n = arr.size();
        for(int j = 0; j <= logs[n]; ++j){
            int len = 1 << j;
            for(int i = 0; i+len <= n; ++i){
                if(len == 1)table[i][j] = arr[i];
                else table[i][j] = min(table[i][j-1],table[i+len/2][j-1]);
            }
        }
    }
    int query(int l, int r){
        int p = logs[r-l+1];
        int len = 1 << p;
        return min(table[l][p],table[r-len+1][p]);
    }
};

int main(){
    Sparse::compute();
    int n,q,l,r;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int &i : arr)scanf("%d",&i);
    Sparse mn(arr);
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        printf("%d\n",mn.query(l,r));
    }
    return 0;
}