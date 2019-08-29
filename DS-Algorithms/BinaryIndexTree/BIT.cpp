#include<bits/stdc++.h>
using namespace std;
const int N = 11;
vector<int> tree;
// vector<int> arr;
int arr[] = {0,3,2,-1,6,5,4,-3,3,7,2,3};
void build(){
    for(int i = 1; i <= N; ++i){
        int x = i;
        int val = arr[i];
        while(x <= N){
            tree[x] += val;
            x+=(x&(-x));
        }
    }
}

int query(int l, int r){
    int ans = 0;
    int x = r;
    while(x > 0){
        ans+=tree[x];
        x-=(x&(-x));
    }
    x = l-1;
    while(x > 0){
        ans-=tree[x];
        x-=(x&(-x));
    }
    return ans;
}

void update(int idx, int val){
    int x = idx;
    int change = val-arr[idx];
    while(x <= N){
        tree[x]+=change;
        x+=(x&(-x));
    }
}


int main(){
    // arr = vector<int> (N+1,0);
    tree = vector<int> (N+1,0);
    build();
    for(int i = 1; i <= N; ++i){
        for(int j = i; j <= N; ++j){
            printf("For range (%d - %d), Sum = %d\n",i,j,query(i,j));
        }
    }
    return 0;
}