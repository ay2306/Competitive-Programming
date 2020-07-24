#pragma GCC Optimize("O3")
#pragma GCC Optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int sumTree[(N+10)<<2],minTree[(N+10)<<2];
int n, k ,temp;

void MinUpdate(int id, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        minTree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)MinUpdate(id,val,node<<1,start,mid);
    else MinUpdate(id,val,node<<1|1, mid+1,end);
    minTree[node] = (minTree[node<<1] < minTree[node<<1|1] ? minTree[node << 1] : minTree[node << 1 | 1]);
}
int MinQuery(int l, int r, int mn, int node = 1, int start= 0, int end = n-1){
    if(start > r || end < l)return -2;
    if(l <= start && end <= r){
        if(minTree[node] >= abs(mn))return -2;
        while(start != end){
            int mid = start + end >> 1;
            if(mn < 0){
                if(minTree[node<<1|1] >= -mn){
                    node=node<<1;
                    end = mid;
                }else{
                    node=node<<1|1;
                    start=mid+1;
                }
            }else{
                if(minTree[node<<1] >= mn){
                    node=node<<1|1;
                    start=mid+1;
                }else{
                    node<<=1;
                    end = mid;
                }
            }
        }
        return start;
    }
    int p,mid = start + end >> 1;
    if(mn < 0){
        int p = MinQuery(l,r,mn,node<<1|1,mid+1,end);
        if(p != -2)return p;
        p = MinQuery(l,r,mn,node<<1,start,mid);
        if(p != -2)return p;
        return -2;
    }
    p = MinQuery(l,r,mn,node<<1,start,mid);
    if(p != -2)return p;
    p = MinQuery(l,r,mn,node<<1|1,mid+1,end);
    if(p != -2)return p;
    return -2;
}

void SumUpdate(int id, int val, int node = 1, int start = 0, int end = n-1){
    if(start == end){
        sumTree[node] = val;
        return;
    }
    int mid = start + end >> 1;
    if(id <= mid)SumUpdate(id,val,node<<1,start,mid);
    else SumUpdate(id,val,node<<1|1, mid+1,end);
    sumTree[node] = sumTree[node<<1] + sumTree[node<<1|1] ;
}
int SumQuery(int l, int r, int node = 1, int start= 0, int end = n-1){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return sumTree[node];
    int mid = start+end >> 1;
    int p1 = SumQuery(l,r,node<<1,start,mid);
    int p2 = SumQuery(l,r,node<<1|1,mid+1,end);
    return p1+p2;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(minTree,minTree+((N+10)<<2),INT_MAX);
    long long ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a)cin >> i;
    set<int> b;
    vector<pair<int,int>> arr;
    while(k--){
        cin >> temp;
        b.emplace(temp);
    }
    for(int i = 0; i < n; ++i){
        MinUpdate(i,a[i]);
        if(b.count(a[i]))continue;
        arr.emplace_back(a[i],i);
    }
    sort(arr.rbegin(),arr.rend());
    while(arr.size()){
        int val = arr.back().first;
        int index = arr.back().second;
        int mn,mid,left,right,hi=index,lo=0;
        left = MinQuery(0,index,-val);
        right = MinQuery(index,n-1,val);
        if(right == -2)right = n;
        if(left == -2)left = -1;
        int deleted = SumQuery(left+1,right-1);
        ans += right-left-1-deleted;
        SumUpdate(index,1);
        MinUpdate(index,INT_MAX);
        arr.pop_back();
    }
    return cout << ans << "\n",0;
}