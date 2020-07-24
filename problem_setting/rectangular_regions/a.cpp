#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x[3],y[3];
        for(int i = 0; i < 3; ++i)cin >> x[i] >> y[i];
        if(x[0] < x[2] && x[1] > x[2] && y[0] < y[2] && y[1] > y[2])printf("INSIDE\n");
        else printf("NOT INSIDE\n");
    }
    return 0;
}