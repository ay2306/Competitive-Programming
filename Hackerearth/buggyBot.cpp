#include<bits/stdc++.h>
#define MAXN 100010
#define MAXM 1000010
#define MAXK 1000010
using namespace std;


int n,m,k,ia[MAXK],ib[MAXK], pos[MAXK], ee[MAXN];
set<int> graph[MAXN], tmp[MAXN], ans
int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < m; ++i){
    int a,b;
    cin >> a >> b;
    graph[a].insert(b);
  }
  for(int i = 0; i < k; ++i){
    cin >> ia[i] >> ib[i];
  }
  pos[0] = 1;
  int cp = 1;
  for(int i = 0; i < k; ++i){
    if(cp == ia[i])cp = ib[i];
    pos[i+1] = cp;
  }
  for(int i = 1; i <= n; ++i){
    ee[i] = i;
  }
  ans.insert(cp);
}
