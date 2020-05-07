//https://codeforces.com/contest/13/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10,K=340;

int nextBlock[N],prevBlock[N],power[N],costToNextBlock[N],steps[N];
// int nextBlock, int steps to next Block 
pair<int,int> nextPosition[N];
int n,a,b,t,m;

void updatePosition(int pos){
    int nxtPos = power[pos] + pos;
    if(nextBlock[pos] <= nxtPos){
        nextPosition[pos] = {nxtPos, pos};
        steps[pos] = 1;
    }else{
        nextPosition[pos] = nextPosition[nxtPos];
        steps[pos] = steps[nxtPos]+1;
    }
}

void updateBlock(int pos,int val){
    int lastBlockPosition = prevBlock[pos];
    power[pos] = val;
    for(; pos >= lastBlockPosition; --pos){
        updatePosition(pos);
    }
}

void build(){
    for(int i = n-1; i >= 0; --i){
        updatePosition(i);
    }
}

void query(int pos){
    int totalSteps = 0;
    int lastPosition = pos;
    while(true){
        totalSteps += steps[pos];
        if(nextPosition[pos].first >= n){
            lastPosition = nextPosition[pos].second;
            break;
        }
        pos = nextPosition[pos].first;
    }
    printf("%d %d\n",lastPosition+1,totalSteps);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        scanf("%d",power+i);
        nextBlock[i] = min(n,(i/K + 1)*K);
        prevBlock[i] = i/K*K;
    }
    build();
    while(m--){
        scanf("%d%d",&t,&a);
        if(t == 0){
            scanf("%d",&b);
            updateBlock(a-1,b);
        }
        else query(a-1);
    }
    return 0;
}