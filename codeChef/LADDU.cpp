#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int score = 0;
        cin >> n;
        string type;
        cin >> type;
        for(int i = 0; i < n; ++i){
            string a;
            cin >> a;
            if(a=="CONTEST_WON"){
                int b;
                cin >> b;
                score+=300;
                if(b<20){
                    score+=(20-b);
                }
            }else if(a=="TOP_CONTRIBUTOR"){
                score+=300;
            }else if(a=="BUG_FOUND"){
                int b;
                cin >> b;
                if(b<50)b=50;
                if(b>1000)b=1000;
                score+=b;
            }else if(a=="CONTEST_HOSTED"){
                score+=50;
            }
        }
        if(type=="INDIAN")cout << score/200 << endl;
        else{cout << score/400 << endl;}
    }
}