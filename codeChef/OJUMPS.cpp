#include<iostream>
using namespace std;

int main(){
    long long int a;
    cin >> a;
    a%=6;
    switch (a)
    {
    case 0:
    case 1:
    case 3: printf("yes");break;
    default:
        printf("no");
    }
    return 0;
}