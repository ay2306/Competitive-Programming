#include<iostream>

using namespace std;

int main(){
string a;
    while(cin >> a){
        int i;
        int scoreA = 0;
        int scoreB = 0;
        int remainingA = 5;
        int remainingB = 5;
        for(i = 0; i < 10; ++i){
            if(i%2==0){
                if(scoreB > remainingA+scoreA)break;
                remainingA--;
                if(a[i]=='1')scoreA++;
            }
            else{
                if(scoreA > scoreB+remainingB){
                    break;
                }
                remainingB--;
                if(a[i]=='1')scoreB++;
            }
        }
        if(scoreA!= scoreB){
                if(i==10){
                    if(scoreA > scoreB)cout << "TEAM-A " << i <<  "\n";
                    if(scoreA < scoreB)cout << "TEAM-B " << i <<  "\n";
                }else{
                    if(scoreA > scoreB)cout << "TEAM-A " << i+1 <<  "\n";
                    if(scoreA < scoreB)cout << "TEAM-B " << i+1 <<  "\n";
                }
            }else{
            for(; i < 20; ++i){
                if(i%2 == 0){
                    if(s[i]=='1' && s[i+1]=='0'){
                        cout << "TEAM-A " << i+2 << "\n";
                        break;
                    }
                }
                if(i%2 == 1){
                    if(s[i]=='1' && s[i-1]=='0'){
                        cout << "TEAM-A " << i+1 << "\n";
                        break;
                    }
                }
            }
        }
        if(i==20)cout << "TIE\n";
    }
}
