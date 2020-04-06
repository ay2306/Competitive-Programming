#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class TrivialWordSearch{
mt19937 generator;  
public:
    TrivialWordSearch(){
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        generator = mt19937(seed);
    }
    vector<string> construct(string w){
        vector<string> a(w.size(),string(w.size(),' '));
        set<char> s;
        for(auto &i: w)s.insert(i);
        if(w.size() == 1)return vector<string> (1,string(1,w[0]));
        if(s.size() <= 1)return vector<string> ();
        a[0] = w;
        char to_chose;
        while(true){
            to_chose = *s.begin();
            if(w[w.size()-1] != to_chose)break;
            s.erase(to_chose);
        }
        for(int i = 1; i < w.size(); ++i)for(auto &j: a[i])j=to_chose;
        return a;
    }
};

int main(){
    TrivialWordSearch a;
    string b;
    cin >> b;
    auto i = a.construct(b);
    for(auto j: i)cout << j << "\n";
}