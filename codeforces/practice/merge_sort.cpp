#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> sorted_segments;

void merge_sort(int l, int r, int &rem){
    if(rem == 0 || l+1 == r){
        sorted_segments.emplace_back(l,r-1);
        return;
    }
    rem-=2;
    int mid = l+r>>1;
    merge_sort(l,mid,rem);
    merge_sort(mid,r,rem);
}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k%2==0)return printf("-1"),0;
    k--;
    merge_sort(0,n,k);
    vector<int> arr(n);
    for(int i = 0, j = n; i < n; ++i,j--)arr[i] = j;
    if(k != 0)return printf("-1"),0;
    for(auto &i: sorted_segments)sort(arr.begin()+i.first,arr.begin()+i.second+1);
    for(int &i: arr)printf("%d ",i);
    return 0;
}