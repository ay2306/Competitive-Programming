#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n,p;
  cin >> n >> p;
  string a;
  cin >> a;
  bool pos = false;
  //first i have to confirm if any period exist or not
  for(int i = 0; i + p < n; ++i){
    if((a[i] != '.' && a[i+p] != '.' && a[i]!=a[i+p])||(a[i] == '.' && a[i+p]!='.')||(a[i+p] == '.' && a[i]!='.')){
      pos = true;
      break;
    }
  }
  if(!pos)cout << "No";
  else{
    for(int i = 0; i < p && i < n; ++i){      
      if(i+p < n){
        // if(i > p){
        //   if(a[i-p] == '1')a[i] = '0';
        //   if(a[i-p] == '0')a[i] = '1';
        // }
        if(a[i] == '.' && a[i+p]=='.'){
          a[i] = '1';
          a[i+p] = '0';
        }
        else if(a[i] == '0' && a[i+p] == '.'){a[i+p] = '1';}
        else if(a[i] == '1' && a[i+p] == '.'){a[i+p] = '0';}
        else if(a[i] == '.' && a[i+p] == '1'){a[i] = '0';}
        else if(a[i] == '.' && a[i+p] == '0'){a[i] = '1';}

      }
      else if(a[i] == '.'){
        a[i]='0';
      }
      
      // cout << a << endl;
    }
    for(int i = p; i < n; ++i){
      if(a[i-p] == '1')a[i] = '0';
      if(a[i-p] == '0')a[i] = '1';
    }
    cout << a;

  }

  return 0;
}
