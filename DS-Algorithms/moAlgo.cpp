#include<bits/stdc++.h>
using namespace std;
int block;

struct Query{
    int L,R;
};

bool compareQuery(Query x, Query y){
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}


void queryResult(int a[], int n, Query q[], int m){
    block = (int)sqrt(n);
    sort(q,q+m,compare);
    int currL = 0, currR = 0;
    int currSum = 0;

    for(int i = 0; i < m; ++i){
        int L = q[i].L;
        int R = q[i].R;
        while(currL < L){
            currSum -= a[currL];
            currL++;
        }
        while(currL > L){
            currSum += a[currL-1];
            currL--;
        }
        while(currR <= R){
            currSum +=
        }
    }
}
int main(){

    return 0;
}