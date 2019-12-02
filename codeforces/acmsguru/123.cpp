#include<iostream>
#define ll long long int
const int N = 42;
ll arr[50];

int main(){
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= 41; ++i)arr[i] = arr[i-1]+arr[i-2];
    int n;
    std::cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; ++i){
        sum+=arr[i];
    }
    std::cout << sum;
    return 0;
}