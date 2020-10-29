#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    auto check = [](int x)->bool{
        if(x % 4 == 0)return false;
        if(x % 2 == 0)x/=2;
        for(int i = 3; i * i <= x; i+=2){
            int cnt = 0;
            while(x%i == 0){
                cnt++;
                x/=i;
                if(cnt == 2)return false;
            }
        }
        return true;
    };
    vector<int> div;
    for(int i = 1; i * i <= n; i++){
        if(n % i)continue;
        div.emplace_back(i);
        if(i*i != n)div.emplace_back(n/i);
    }
    sort(div.begin(),div.end());
    while(1){
        if(check(div.back()))return cout << div.back(), 0;
        div.pop_back();
    }
    return 0;
}