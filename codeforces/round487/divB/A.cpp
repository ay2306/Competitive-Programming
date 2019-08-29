#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a;
  cin >> a;
  int sum = 'A' + 'B' + 'C';
  bool pos = false;
  for(int i = 1; i+1 < a.length(); ++i){
    int arr[3] = {0};
    arr[a[i-1]-'A']++;
    arr[a[i]-'A']++;
    arr[a[i+1]-'A']++;
    if(arr[0] && arr[1] && arr[2]){
      pos = true;
      break;
    }
  }
  if(pos)cout << "Yes";
  else cout << "No";
  return 0;
}
