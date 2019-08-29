#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t;
    cin >> t;
    while(t--){
        long long int tmp,n,k;
        bool no_negative = true;
        bool first_negative = true;
        cin >> n >> k;
        vector<long long int> arr;
        long long int sum = 0;
        long long int sum_first_positive = 0;
        long long int sum_last_postive = 0;
        for(long long int i = 0; i < n; ++i){
            cin >> tmp;
            arr.push_back(tmp);
            sum_last_postive+=tmp;
            if(tmp < 0){
                sum_last_postive = 0;
                if(first_negative){
                    sum_first_positive = sum;
                    first_negative = false;
                }
                no_negative = false;
            }
            sum+=tmp;
        }
        long long int mx = 0;
        if(no_negative){
            cout << sum*k << "\n";
        }
        else{
            if(sum*k > sum_first_positive+sum_last_postive)cout << sum*k << "\n";
            else{
                cout << sum_first_positive+sum_last_postive << "\n";
            }
        }
    }
return 0;
}
