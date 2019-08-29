#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        double x1,x2,x3,v1,v2;
        cin >> x1 >> x2 >> x3 >> v1 >> v2;
        double f1 = ((x3-x1)/v1);
        double f2 = ((x3-x2)/v2);
        if(f1 < 0)f1*=-1;
        if(f2 < 0)f2*=-1;
        // cout << f1 << "\t" << f2 << endl; 
        if(f1 == f2)cout << "Draw\n";
        else if(f1 > f2) cout << "Kefa\n";
        else cout << "Chef\n";
    }
return 0;
}