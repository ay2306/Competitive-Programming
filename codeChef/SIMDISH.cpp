#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        vector<string> a,b;
        for(int i = 0; i < 4; ++i){
            cin >> str;
            a.push_back(str);
        }
        for(int i = 0; i < 4; ++i){
            cin >> str;
            b.push_back(str);
        }
        int cnt = 0;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                if(a[i]==b[j])cnt++;
            }
        }
        if(cnt>=2)cout << "similar\n";
        else{cout << "dissimilar\n";}
    }
    return 0;
}