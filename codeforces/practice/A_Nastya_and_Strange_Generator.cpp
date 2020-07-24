#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   scanf("%d",&t);
   while(t--){
       int n;
       scanf("%d",&n);
       vector<int> arr(n);
       for(int &i: arr)scanf("%d",&i);
       map<int,int> m;
       for(int i = 0; i < n; ++i)m[arr[i]] = i;
       int cur = 1, lst = n, valid = 1;
       while(cur <= n && valid){
           int id = m[cur];
           valid = is_sorted(arr.begin()+id,arr.begin()+lst);
           int cnt = lst - id;
           lst = id;
           cur+=cnt;
       }
       if(valid)printf("Yes\n");
       else printf("No\n");
   }
   return 0;
}