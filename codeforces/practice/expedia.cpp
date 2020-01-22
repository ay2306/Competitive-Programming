ll dp[1010][1010];
ll dis[1010] = {0};
ll vis[1010] = {0};
for(int i = 0; i < A.size(); ++i){
    dis[j]=1000*1000.
    for(int j = 0; j < A[i].size(); ++j)dp[i][A[i][j]]=1;
}
dis[0]=0;
queue<int> q;
q.push(0);
vis[0] = 1;
while(!q.empty()){
    for(int i = 0; i < A.size(); ++i){
        if(!vis[i] && dp[q.front()][i]){
            q.push(i);
            dis[i]=dis[q.front()]+1;
            vis[i]=true;
        }
    }
    q.pop();
}
if(!vis[A.size()-1])return -1;
return dp[A.size()-1];

//

int binary_search(int lo, int hi, unordered_map<int,int> &m, int A){
    if(lo > hi)return 0;
    int mid = (lo+hi)/2;
    int pos = 0;
    for(unordered_map<int,int>::iterator itr = m.begin(); itr != m.end(); ++itr){
        pos+=(itr->second/mid);
    }
    if(pos >= A){
        return max(binary_search(lo,mid,m,A),mid);
    }
    return binary_search(mid+1,hi,m,A);
}

unordered_map<int,int> m;
for(int itr: B)m[itr]++;
return binary_search(1,B.size()+10,m,A);