#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin,s);
    for(char &i: s)if(!isalpha(i)) i = '.';
    int lo = 1, hi = s.size(), ans = hi;
    while(lo <= hi){
        int mid = lo + hi >> 1;
        int lines = 1, current = 0, currentLine = 0;;
        for(int i = 0; i < s.size(); ++i){
            current++;
            currentLine++;
            if(currentLine > mid)lines++,currentLine = current;
            if(currentLine > mid){
                lines = n+1;
                break;
            }
            if(s[i] == '.')current = 0;
        }
        if(lines > n)lo = mid+1;
        else hi = mid-1, ans = mid;
    }
    cout << ans ;
    return 0;
}