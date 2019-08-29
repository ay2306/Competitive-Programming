#include<bits/stdc++.h>

using namespace std;


int main(){
int t;
cin >> t;
while(t--){
    int n;
    cin >> n;
    int c1,c2,c3,d1,d2,d3;
    c1 = 0; c2 = 0; c3 = 0; d1 = 0; d2 = 0; d3 = 0;
    int a,b,c;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        if(b == 1){
            if(d1 < c){
                d1 = c;
                c1 = a;
            }else if(d1 == c){
                if(c1 > a)c1=a;
            }
        }
        if(b == 2){
            if(d2 < c){
                d2 = c;
                c2 = a;
            }else if(d2 == c){
                if(c2 > a)c2=a;
            }
        }if(b == 3){
            if(d3 < c){
                d3 = c;
                c3 = a;
            }else if(d3 == c){
                if(c3 > a)c3=a;
            }
        }
    }
    cout << d1 << " " << c1 << "\n" << d2 << " " << c2 << "\n" << d3 << " " << c3 << "\n";
}


return 0;
}
