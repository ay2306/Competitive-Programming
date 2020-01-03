#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main(){
    ord_set<pair<int,int>> s;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)cin >> arr[i];
    s.insert({arr[n-1],n-1});
    arr[n-1] = 0;
    for(int i = n-2; i >= 0; --i){
        s.insert({arr[i],i});
        arr[i] = s.order_of_key({arr[i],i});
    }
    for(int i = 0; i < n; ++i)cout << arr[i] << " ";
   return 0;
}