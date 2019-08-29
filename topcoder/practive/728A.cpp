#include<bits/stdc++.h>
using namespace std;

class HalvingEasy{
    public:
    int count(vector<int> a, int k){
        int ans = 0;
        for(auto i: a){
            while(i){
                if(i == k){
                    ans++;
                    break;
                }
                i/=k;
            }
        }
        return ans;
    }
};