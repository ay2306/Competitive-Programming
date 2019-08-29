#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        // cout << a << " " << b;
        int a_length = a.length();
        int b_length = b.length();
        int k = a_length - b_length;
        int i = 0;
        int j = 0;
        int num = 0;
        if(k>0){
            while(k){
                num*=10;
                num+=(a[i++]-48);
                --k;
            }
        }
        else if(k<0){
            k*=-1;
            while(k){
                num*=10;
                num+=(b[j++]-48);
                --k;
            }
        }
        while(i<a.length() && j<b.length()){
            k = (a[i++]-48)+(b[j++]-48);
            k = k % 10;
            num*=10;
            num+=k;
        }
        cout << num << endl;
    }
}