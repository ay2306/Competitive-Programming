#include <iostream>

using namespace std;
int main(){
//ios_base::sync_with_std(false);
//cin.tie(NULL);
int t;
cin >>  t;
while(t--){
    string s;
    cin >> s;
    int A=0,B=0;
    int i = 0;
    char left='C';
    for(int j = 0; j < s.length(); ++j){
        if(s[j]=='A'){
            ++A;
            if(left == s[j]){
                A+=i;
            }
            left = 'A';
            i = 0;
        }
        if(s[j]=='B'){
            ++B;
            if(left == s[j]){
                B+=i;
            }
            left = 'B';
            i = 0;
        }
        if(s[j]=='.'){
            ++i;
        }
    }
    cout << A << " " << B << "\n";
}
return 0;
}
