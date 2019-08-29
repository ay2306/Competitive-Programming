#include <bits/stdc++.h>
using namespace std;

int getLevel(int arr[], int a){
  int lev = 0;
  while(a){
    lev++;
    a = arr[a-1];
  }
  return lev;
}

unsigned long long int shake(int n, int a){
  return (n-a)*a;
}
unsigned long long int bump(int a){
  return (a*(a-1))/2;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    unsigned long long int shakes = 0,bumps = 0;
    int n;
    cin >> n;
    int *arr = new int[n];
    int *level = new int[n];
    for(int i = 0; i < n; ++i){cin >> arr[i];level[i] = 0;}
    for(int i = 0; i < n; ++i){level[i] = getLevel(arr,arr[i]);}
    map<int,int> m;
    for(int i = 0; i < n; ++i){
      if(m.count(level[i]) == 0){
        m.insert(make_pair(level[i],1));
      }else{
        m.find(level[i])->second++;
      }
    }
    for(map<int,int>::iterator itr = m.begin(); itr != m.end(); ++itr){
      // cout << itr->first << "  " << itr->second << endl;
      shakes+=shake(n,itr->second);
      bumps+=bump(itr->second);
      // cout << shakes << " " << bumps << endl;
    }
    cout << shakes/2 << " " << bumps << endl;
  }
return 0;
}
