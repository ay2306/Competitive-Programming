#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    for(int i = 0; i < 50; ++i)a.push_back(i+1);
    int *arr = new int[50];
    for(int i = 0; i < 50; ++i)arr[i] = i+1;
    cout << *(arr+10) << endl << *(a.begin()+10) << endl;
}