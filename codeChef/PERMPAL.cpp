#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        queue<int> q[26];
        int char_count[26] = {0};
        bool one_odd = false;
        bool pos = true;
        string a;
        int odd_one = -1;
        cin >> a;
        for(int i = 0; i < a.length(); ++i){
            char_count[a[i]-97]++;
            q[a[i]-97].push(i);
        }
        for(int i = 0; i < 26; ++i){
            if(char_count[i]%2==1){
                if(!one_odd)one_odd = true;
                else{
                    pos = false;
                    break;
                }
            }
        }
        if(!pos)cout << "-1\n";
        else{
            for(int i = 0; i < 26; ++i){
                int k = q[i].size();
                if(k%2==1){
                    odd_one = i;
                    continue;
                }
                for(int j = 0; j < k/2; ++j){
                    cout << q[i].front()+1 << " ";
                    q[i].pop();
                }
            }
            if(odd_one!= -1){

                while(!q[odd_one].empty()){
                    cout << q[odd_one].front()+1 << " ";
                    q[odd_one].pop();
                }
            }
            for(int i = 25; i >= 0; --i){
                while(!q[i].empty()){
                    cout << q[i].front()+1 << " ";
                    q[i].pop();
                }
            }
            cout << endl;
        }
    }
}