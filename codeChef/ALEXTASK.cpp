#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b,a%b);
}
/*
int main(){
    int t;
    cin >> t;
    while(t--){
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        int n,a;
        cin >> n >> a;
        min1 = a;
        cin >> a;
        if(a<min1){
            min2 = min1;
            min1 = min2;
        }else{
            min2 = a;
        }
        for(int i = 2; i < n; ++i){
            cin >> a;
            if(min1 > a){
                min2 = min1;
                min1 = a;
            }else if(min2 > a){
                min2 = a;
            }
        }
        int g = gcd(min1,min2);
        int l = min1*min2;
        l/=g;
        cout << l << endl;
    }
}*/

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m = INT_MAX;
        int *arr = new int[n];
        int *tmp = new int[n-1];
        for(int i =0 ; i < n; ++i){
            cin >> arr[i];
            if(m>arr[i])m=arr[i];
        }
        int k = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i] == m)continue;
            int g = gcd(m,arr[i]);
            int l = (m*arr[i])/g;
            tmp[k++] = l;
        }
        m = INT_MAX;
        for(int i =0 ; i < n-1; ++i){
            if(m>tmp[i])m=tmp[i];
        }
        cout << m << endl;
    }
    
    return 0;
}
