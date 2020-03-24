#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin >> a;
    map<char,int> m;
    for(auto &i:a)m[i]++;
    vector<map<char,int>::iterator> arr;
    for(auto i = m.begin(); i != m.end(); ++i)if(i->second & 1)arr.emplace_back(i);
    {
        int i = 0;
        int j = arr.size()-1;
        while(i < j){
            arr[i++]->second++;
            arr[j--]->second--;
        }
    }
    for(auto i = m.begin(); i != m.end(); ++i)cout << string(i->second>>1,i->first);
    for(auto &i: m)if(i.second &1 )cout << i.first;
    for(auto i = m.rbegin(); i != m.rend(); ++i)cout << string(i->second>>1,i->first);
   return 0;
}