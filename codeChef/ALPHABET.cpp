#include<iostream>
using namespace std;

int main(){
    string a;
    cin >> a;
    bool arr[26];
    for(int i = 0; i < 26; ++i)arr[i]=false;
    for(int i = 0; i < a.length(); ++i)arr[a[i]-97] = true;
    int n;
    cin >> n;
    while(n--){
        string b;
        bool pos = true;
        cin >> b;
        for(int i = 0; i < b.length(); ++i){pos=(pos && arr[b[i]-97]);if(!pos)break;}
        if(pos)cout << "Yes\n";
        if(!pos)cout << "No\n";
    }
return 0;
}