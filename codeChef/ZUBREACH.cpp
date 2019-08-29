#include<iostream>
using namespace std;

int main(){
    int t;
    int r = 1;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int Rx,Ry;
        cin >> Rx >> Ry;
        int o;
        cin >> o;
        string a;
        cin >> a;
        int r_x = 0;
        int r_y = 0;
        for(int i = 0; i < a.length(); ++i){
            if(a[i]=='U')r_y++;
            if(a[i]=='D')r_y--;
            if(a[i]=='R')r_x++;
            if(a[i]=='L')r_x--;
        }
        cout << "Case "<< r << ": ";
        if(r_x==Rx && r_y==Ry)cout << "REACHED\n";
        else if(r_x>m || r_y>n || r_x<0 || r_y<0)cout << "DANGER\n";
        else{cout << "SOMEWHERE\n";}
        r++;
    }
return 0;
}