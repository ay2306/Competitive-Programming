#include<iostream>

using namespace std;

int main(){
int t;
cin >> t;
while(t--){
    int n,k,s;
    cin >> n >> k >> s;
    if((k>n) || ((6*(n-k))<k)){
        cout << "-1\n";
        continue;
    }
    int numberOfChocolates = k*s;
    cout << ((numberOfChocolates/n)+1) << endl;
}

return 0;}
