#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    pair<int,int> a[3];
    for(int i = 0; i < 3; ++i)cin >> a[i].first, a[i].second = i+1;
    sort(a,a+3);
    cout << "First" << endl;
    auto First = [&]()->int{
        return 2*a[2].first - a[1].first - a[0].first; 
    };
    auto Second = [&](int to_skip)->int{
        return a[2].first - a[1].first - a[0].first + a[to_skip].first; 
    };
    int x;
    cout << First() << endl;
    cin >> x;
    if(x == a[2].second){
        a[2].first += First();
        cout << First() << endl;
        cin >> x;
    }
    x = (x == a[1].second);
    cout << Second(x) << endl;
    cin >> x;
    return 0;
}