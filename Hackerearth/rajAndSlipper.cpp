#include<bits/stdc++.h>
using namespace std;
int convert(string a){
  int hrs,min;
  int b=0;
  int i;
  for(i = 0; a[i]!=':';++i){
      b=(b*10) + (a[i]-'0');
  }
  hrs = b;
  ++i;
  b=0;
  for(i = 0; i < a.length();++i){
      b=(b*10) + (a[i]-'0');
  }
  min = b;
  return ((60*hrs)+min);
}

bool storeSelectionPossibility(int store, int r, int s, int hostel){
  if(store + r + s <= hostel)return true;
  return false;
}

bool check(pair<int,int>slipper, int wake, int hostel, int store, int r, int s){
  //There are two cases 1 we can do it before slippers are busy or after they are free
  //Checking for case 1

}

int main(){
  int t;
  cin >> t;
  for(int Case = 1; Case <= t; Case++){
    int n;
    cin >> n;
    std::vector<pair<int,int> > v;
    string a;
    cin >> a;
    int hostel = convert(a);
    cin >> a;
    int wake = convert(a);
    cin >> a;
    int store = convert(a);
    int r,s;
    cin >> r >> s;
    for(int i = 0; i < n; ++i){
      cin >> a;
      string b;
      cin >> b;
      v.push_back(make_pair(convert(a),convert(b)));
    }
    if(storeSelectionPossibility(store,r,s,hostel)){
      int i;
      for(i = 0; i < n; ++i){
        if(check(v[i],wake,hostel,store,r,s)){
          break;
        }
      }
      if(i != n)printf("Case %d: %d\n",Case,i+1 );
    }
  }
}
