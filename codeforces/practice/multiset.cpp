//https://codeforces.com/contest/1354/problem/D?mobile=false
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
int bit[N],n,a,q;

void update(int x, int val){
    ++x;
    while(x < N){
        bit[x]+=val;
        x+=(x&-x);
    }
}

int query(int x, int res = 0){
    ++x;
    while(x > 0){
        res+=bit[x];
        x-=(x&-x);
    }
    return res;
}

int findKth(int k){
    int lo = 0;
    int hi = 1e6;
    int num = -1;
    while(lo <= hi){
        int mi = lo + hi >> 1;
        if(query(mi)>=k)num = mi,hi = mi - 1;
        else lo = mi + 1;
    }   
    return num;
}

int main(){
    scanf("%d%d",&n,&q);
    while(n--){
        scanf("%d",&a);
        update(a,1);
    }
    while(q--){
        scanf("%d",&a);
        if(a >= 1)update(a,1);
        else{
            a = abs(a);
            int val = findKth(a);
            if(~val)update(val,-1);
        }
    }
    int val = findKth(1);
    if(~val)return printf("%d\n",val),0;
    return printf("0\n"),0;
}

