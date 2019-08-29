#include<iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string team1 = "";
        string team2 = "";
        string tmp;
        int team1_goals = 0;
        int team2_goals = 0;
        cin >> k;
        while(k--){
            cin >> tmp;
            if(team1 == ""){team1=tmp;team1_goals++;}
            else if(tmp == team1)team1_goals++;
            else if(team2 == ""){team2=tmp;team2_goals++;}
            else if(team2 == tmp){team2_goals++;}
        }
        if(team2_goals == team1_goals)cout << "DRAW\n";
        else if(team1_goals > team2_goals)cout << team1 << "\n";
        else if(team2_goals > team1_goals)cout << team2 << "\n";
    }
}
