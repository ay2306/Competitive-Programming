#include <bits/stdc++.h>
using namespace std;

int main(){
  map<int,pair<string,string> > m1;
  map<string,int> m2;

  m1.insert(make_pair(1,make_pair("","")));
  m2.insert(make_pair("",1));
  int n,q;
  cin >> n >> q;
  for(int i = 1; i < n; ++i){
    int parent,current;
    string path;
    string mirror_path;
    if(path == "R")mirror_path = "L";
    else if(path == "L")mirror_path = "R";
    cin >> parent >> current >> path;
    m1.insert(make_pair(current,make_pair((m1.find(parent)->second).first + path,(m1.find(parent)->second).second + mirror_path)));
    m2.insert(make_pair((m1.find(parent)->second).first + path, current));
  }
//   for(map<int,string>::iterator itr = m1.begin(); itr!=m1.end(); ++itr){
//     cout << itr->first << "  " << itr->second << endl;
//   }
//   cout << "NOW ENTER QUERRIES\n";
  for(int i = 0; i < q; i++){
    int a;
    cin >> a;
    string path = (m1.find(a)->second).second;
    // cout << path << endl;
    if(m2.count(path) == 0){
      cout << "-1\n";
    }else{
      cout << m2.find(path)->second << endl;
    }
  }
return 0;
}
