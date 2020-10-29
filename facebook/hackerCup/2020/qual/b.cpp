#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; ++test){
        int n;
        cin >> n;
        string a;
        cin >> a;
        stack<char> s;
        for(char i: a){
            if(s.size() > 1){
                string temp = "";
                temp+=i;
                temp+=s.top();
                s.pop();
                temp+=s.top();
                s.pop();
                sort(temp.begin(),temp.end());
                if(temp[0] == temp[2]){
                    s.emplace(temp[2]);
                    s.emplace(temp[1]);
                }
                else if(temp[0] == temp[1])i='A';
                else i = 'B';
            }
            s.emplace(i);
        }
        a = "";
        while(s.size())a+=s.top(),s.pop();
        for(char i: a){
            if(s.size() > 1){
                string temp = "";
                temp+=i;
                temp+=s.top();
                s.pop();
                temp+=s.top();
                s.pop();
                sort(temp.begin(),temp.end());
                if(temp[0] == temp[2]){
                    s.emplace(temp[2]);
                    s.emplace(temp[1]);
                }
                else if(temp[0] == temp[1])i='A';
                else i = 'B';
            }
            s.emplace(i);
        }
        cout << "Case #" << test << ": " << (s.size() == 1?'Y':'N') << "\n";
    }
    return 0;
}