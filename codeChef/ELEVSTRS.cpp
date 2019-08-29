#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        float n,v1,v2;
        cin >> n >> v1 >> v2;
        float d_e = n;
        float d_s = n*sqrt(2);
        float t_e = n/v2;
        t_e*=2;
        float t_s = d_s/v1;
        if(t_s<t_e){
            cout << "Stairs\n";
        }else{
            cout << "Elevator\n";
        }
    }
return 0;
}