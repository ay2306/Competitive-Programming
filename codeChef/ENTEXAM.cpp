#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<unsigned long long int> vec;
        int n,k,e;
        unsigned long long int m;
        cin >> n >> k >> e >> m;
        unsigned long long int sum = 0;
        for(int i = 0; i < n-1 ; ++i){
            int a;
            sum = 0;
            for(int j = 0; j < e; ++j){
                cin >> a;
                sum+=a;
            }
            vec.push_back(sum);
        }
        sort(vec.begin(), vec.end());
        sum = 0;
        unsigned long long int marks_req;
        marks_req = vec[k-1];
        marks_req++;
        for(int i = 0; i < e-1; ++i){
            int a;
            cin >> a;
            sum+=a;
        }
        if(marks_req > sum + m)cout << "Impossible\n";
        else if(marks_req < sum)cout << "0\n";
        else if(marks_req == sum+m) cout << m << "\n";
        else if(marks_req < sum+m) cout << (marks_req-sum) << "\n";
    }
return 0;
}