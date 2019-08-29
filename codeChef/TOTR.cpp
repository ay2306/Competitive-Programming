#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a;
    cin >> n >> a;
    unordered_map<char,char> m;
    for(char i = 'a'; i <= 'z'; ++i){
        m[i]=a[i-'a'];
    }
    while(n--){
        cin >> a;
        for(char &i: a){
            if(i >= 'a' && i <= 'z'){
                cout << m[i];
            }
            else if(i >= 'A' && i <= 'Z'){
                cout << char(m[char(i+32)] - 32);
            }
            else if(i == '_'){
                cout << " ";
            }else{
                cout << i;
            }
        }
        cout << "\n";
    }
    return 0;
}