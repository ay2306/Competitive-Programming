//https://codeforces.com/contest/652/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    int n;
    scanf("%d",&n);
    ord_set<int> s;
    vector<pair<pair<int,int>,int>> arr(n);
    for(int i = 0; i < n; ++i)scanf("%d%d",&arr[i].first.second,&arr[i].first.first),arr[i].second = i;
    sort(arr.begin(),arr.end());
    vector<int> ans(n);
    for(auto &i: arr){
        ans[i.second] = (int)s.size() - (int)s.order_of_key(i.first.second);
        s.insert(i.first.second);
    }
    for(auto &i: ans)printf("%d\n",i);
    return 0;
}