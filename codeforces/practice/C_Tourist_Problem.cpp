#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;

using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


signed main(){
    int n;
    cin >> n;
    int denom = n*(n-1)*(n-2);
    int num = 0;
    vector<int> a(n);
    ord_set<pair<int,int>> s;
    for(int &i: a)cin >> i;
    for(int i = 0; i < n; ++i){
        int small = s.order_of_key(pair<int,int>(a[i],-1));
        int large = n-1-small;
        int add = 0;
        add+=(small*(small-1))*a[i];
        add-=(large*(large-1))*a[i];
        cout << small << " " << large << " " << add << endl; 
        add+=2*(small-large)*a[i]*(n-2);
        cout << small << " " << large << " " << add << endl; 
        add+=a[i]*(n-1)*(n-2);
        // add+=(small-large)*a[i]*(n-1);
        num+=add;
        cout << small << " " << large << " " << add << endl; 
        s.insert(pair<int,int>(a[i],i));
    }
    int g = __gcd(num,denom);
    cout << num/g << " " << denom/g;
    return 0;
}