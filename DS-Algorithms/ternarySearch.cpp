#include<iostream>
#include<vector>

using namespace std;

int ternarySearch(vector<int> arr, int l, int r, int x){
    if(r>=l){
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1]==x)return mid1;
        if(arr[mid2]==x)return mid2;
        if(x < arr[mid1])return ternarySearch(arr,l,mid1-1,x);
        else if(x > arr[mid2])return ternarySearch(arr,mid2+1,r-1,x);
        return ternarySearch(arr,mid1+1,mid2-1,x);
    }
    return -1;
}

int main(){
    vector<int> arr;
    for(int i = 1; i < 50001; ++i)arr.push_back(i);
    int index = ternarySearch(arr,0,arr.size(),87);
    cout << arr[index] << "\t";
    index = ternarySearch(arr,0,arr.size(),544);
    cout << arr[index] << "\t";
    index = ternarySearch(arr,0,arr.size(),8465);
    cout << arr[index] << "\t";
    index = ternarySearch(arr,0,arr.size(),1321);
    cout << arr[index] << "\t";
    return 0;
}
