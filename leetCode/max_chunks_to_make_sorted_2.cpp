#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> a;
        for(auto i: arr)a.push_back(i);
        sort(a.begin(),a.end());
        unordered_map<int,pair<int,int> > m;
        printf("MAPPING\n");
        for(int i = 0; i < arr.size(); ++i){
            if(m.find(a[i]) == m.end()){
                m[a[i]] = make_pair(i,i);
            }else{
                m[a[i]].second = i;
            }
            printf("a[i] = %d and m[%d] = (%d,%d)\n",a[i],a[i],m[a[i]].first,m[a[i]].second);
        }
        printf("MAPPING\n");
        int ans = 0;
        pair<int,int> c = make_pair(0,0);
        for(int i = 0; i < arr.size(); ++i){
            if(m[arr[i]].first > c.first){
                c.first = m[arr[i]].first;
                c.second = m[arr[i]].second;
            }
            printf("i = %d, arr[i] = %d, c = (%d,%d), m[arr[i]] = (%d,%d)",i,arr[i],c.first,c.second,m[a[i]].first,m[a[i]].second);
            if(i >= c.first && i <= c.second)ans++;
            cout << ans << endl;
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    Solution s;
    cout << s.maxChunksToSorted(a) << endl;
}