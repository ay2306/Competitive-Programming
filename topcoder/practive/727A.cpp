#include <bits/stdc++.h>
using namespace std;

class MakeTwoConsecutive{
    public:
    string solve(string a){
        if(a.length() <= 2)return "Impossible";
        for(int i = 1; i < a.length(); ++i){
            if(a[i] == a[i-1])return "Possible";
        }
        return "Impossible";
    }
};