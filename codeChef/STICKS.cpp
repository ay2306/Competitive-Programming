#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,n;
        cin >> n;
        vector<int> vec;
        int max1 = -1;
        int max2 = -1;
        for(int i = 0; i < n; ++i){
            cin >> a;
            vec.push_back(a);
        }
        sort(vec.begin(),vec.end());
        for(int i = 1; i < vec.size(); ++i){
            if(vec[i]==vec[i-1]){
                if(vec[i]>max1){
                    max2 = max1;
                    max1 = vec[i];
                    ++i;
                }else if(vec[i]>max2){
                    max2 = vec[i];
                    ++i;
                }
            }
        }
        if(max1>0 && max2>0)cout << max1*max2 << endl;
        else{cout << "-1\n";}
    }
    return 0;
}