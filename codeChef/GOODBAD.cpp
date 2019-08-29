#include<iostream>
#include<string.h>
using namespace std;


int main(){
int t;
cin >> t;
while(t--){
    string a;
    int n,k;
    int c = 0;
    cin >> n >> k;
    int lowerChar = 0;
    int upperChar = 0;
    cin >> a;
    for(int i = 0; i < a.length(); ++i){
        if(a[i]>=65 && a[i]<=90){
            upperChar++;
            continue;
        }
        lowerChar++;
    }
    if(lowerChar<=k)c++;
    if(upperChar<=k)c+=2;
    if(c==1)cout << "brother\n";
    if(c==2)cout << "chef\n";
    if(c==3)cout << "both\n";
    if(c==0)cout << "none\n";
}
return 0;
}
