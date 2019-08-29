#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(n>m)swap(n,m);
        if(n==1 && m ==1)cout << "No\n";
        else if(((n%2==0) || (m%2==1)))cout << "No\n";
        else {cout << "Yes\n";}
    }
return 0;
}