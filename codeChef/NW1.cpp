#include<iostream>
#include<map>
using namespace std;

int main(){
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    map<string,int> m;
    m["mon"] = 0;
    m["tues"] = 1;
    m["wed"] = 2;
    m["thurs"] = 3;
    m["fri"] = 4;
    m["sat"] = 5;
    m["sun"] = 6;
    int ans[7] = {0};
    string a;
    cin >> a;
    int l = m[a];
    for(int i = 0; i < n; ++i){
        ans[(l+i)%7]++;
    }
    for(int i = 0; i < 7; ++i)cout << ans[i] << " ";
    cout << "\n";
}
return 0;
}
