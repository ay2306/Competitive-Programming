#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        for(char &i: a)i = islower(i) ? toupper(i) : tolower(i);
        cout << a << "\n";
    }
    return 0;
}