#include<bits/stdc++.h>
using namespace std;

struct suffix{
    int index;
    int rank[2];
}

typedef struct suffix sf;

int cmp(sf a, sf b){
    return (a.rank[0] == b.rank[0])?(a.rank[1] < b.rank[1]):(a.rank[0] < b.rank[0]);
}

