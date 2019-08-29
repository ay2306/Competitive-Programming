#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        if(k == 0){
            cout << "a\n";
            continue;
        }
        for(int i = 0; i < (k/25); ++i){
            for(char j = 'z'; j >= 'a'; --j)cout << char(j);
        }
        k = k%25;
        if(k == 0){
            cout << "\n";
            continue;
        }
        for(int i = 'a'+k; i >= 'a'; --i)cout << char(i);
        cout << "\n";
    }
    return 0;
}