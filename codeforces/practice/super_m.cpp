//https://codeforces.com/contest/592/problem/D
#include<bits/stdc++.h>
using namespace std;

/**
 * <summary>
 * 
 * Global variable declarations
 * 
 * 1. N = Maximum size
 * 2. n = Number of cities
 * 3. m = Number of cities under attack
 * 4. g = Adjacency List for graph data
 * 5. sub = Number of attacked cities in subtree of indexed node
 * 6. lev = distance from root of any node (changes when dfs called from some other root)
 * 7. parent = parent of any node
 * 8. s = set of attacked cities
 * 9. total = total number of nodes in reduced graph
 * 10. Others = Helping Variables
 * </summary>
*/

const int N = 2e5;
int n,m,a,b,total;
set<int> s;
vector<int> g[N];
int sub[N],lev[N],parent[N];

/**
 * <Summary>
 *  @name : evil destroyer
 *  @work : Starting from some attacked cities, it drops all the subtrees 
 *          where no city is attacked.
 *  @params:
 *        - s = current node 
 *          size = (32 bit integer)
 *        - p = parent node (-1 for root as it is impossible)
 *          size = (32 bit integer)
 * </Summary>
*/

void evil_destroyer(int s, int p = -1){
    sub[s] = ::s.count(s);
    stack<int> to_delete;
    for(int j = 0; j < (int)g[s].size(); ++j){
        int i = g[s][j];
        if(i == p)continue;
        evil_destroyer(i,s);
        sub[s] += sub[i];
        if(sub[i] == 0)to_delete.push(j);
    }
    while(to_delete.size()){
        int u = to_delete.top();
        int v = (int)g[s].size()-1;
        swap(g[s][u],g[s][v]);
        g[s].pop_back();
        to_delete.pop();
    }
}

/**
 * <Summary>
 *  @name : dfs
 *  @work : A simple depth first search but responsible for finding farthest node
 *          and assigning parents so that path can be retieved
 *  @return: Integer (32-bits) denoting the farthest node
 *  @params:
 *        - s = current node
 *          size = (32 bit integer)
 *        - p = parent node (-1 for root as it is impossible)
 *          size = (32 bit integer)
 * </Summary>
*/

int dfs(int s, int p = -1){
    int mx = s;
    parent[s] = p;
    sub[s] = 1;
    if(p == -1)lev[s] = 0;
    else lev[s] = lev[p] + 1;
    for(int &i: g[s]){
        if(i == p)continue;
        int proposed_max = dfs(i,s);
        sub[s] += sub[i];
        if(lev[proposed_max] > lev[mx])mx=proposed_max;
    }
    total = max(total,sub[s]);
    return mx;
}

/**
 * <Summary>
 *  @name : center
 *  @work : Retrieve Diameter and computes center and find smallest extreme
 *  @return: Integer (32-bits) denoting the smallest node for extreme of diameter
 *  @params: 
 *      - s = any extreme end of the diameter
 *        size = (32 bit integer)
 * </Summary>
*/

int center(int s){
    vector<int> path;
    while(~s){
        path.emplace_back(s);
        s = parent[s];
    }
    int Center = path[path.size() >> 1];
    dfs(Center);
    int mx = *max_element(lev,lev+N);
    int smallest_extreme = N;
    for(int i = 1; i < N; ++i)if(lev[i] == mx)smallest_extreme = min(smallest_extreme,i);
    if(path.size() % 2 == 0){
        Center = path[(path.size()>>1)-1];
        dfs(Center);
        mx = *max_element(lev,lev+N);
        for(int i = 1; i < N; ++i)if(lev[i] == mx)smallest_extreme = min(smallest_extreme,i);
    }
    return smallest_extreme;
}


/**
 * 
 * Driver main function (I know this sounds like geeksforgeeks)
 * return type: signed (no reason I think it is cooler)
 * 
*/

signed main(){
    scanf("%d%d",&n,&m);
    //   -----------------
    //  | Creating Graph  |
    //   -----------------
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    //   --------------------------
    //  | Getting Attacked cities  |
    //   --------------------------
    for(int i = 1; i <= m; ++i){
        scanf("%d",&a);
        s.emplace(a);
    }
    //   ----------------------
    //  | Handling Edge Cases  |
    //   ----------------------
    if(m == 1){
        return printf("%d\n0",*s.begin()),0;
    }
    //   ----------------------
    //   -----------------------
    //  | Deleting waste graph  |
    //   -----------------------
    evil_destroyer(*s.begin());
    //   --------------------------
    //  | Finding center of graph  |
    //   --------------------------
    int extreme = dfs(dfs(*s.begin()));
    int diameter = lev[extreme];
    int smallest_extreme = center(extreme);
    //   ----------------------------------------
    //  | Answer = 2*number of edges - Diameter  |
    //   ----------------------------------------
    //   ----------------------------
    //  | Edges = number of node -1  |
    //   ----------------------------
    printf("%d\n%d\n",smallest_extreme,2*(total-1)-diameter);   
    return 0;
}