#include<iostream>

using namespace std;

int bubbleSort(int arr[], int n)
{
   int i, j;
   int cnt = 0;
   for (i = 0; i < n-1; i++)      
 
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
       {   if (arr[j] > arr[j+1])
           {
               cnt++; 
               int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
           }
}
    return cnt;
}

int main(){
    int arr[10];
    int k = 0;
    for(int i = 9; i >= 0; --i,++k)arr[k]=i+1;
    for(int i = 0; i < 10; i++)cout << arr[i] << "\t";
    cout << "\n";
    cout << bubbleSort(arr,10) << endl;
    for(int i = 0; i < 10; ++i)cout << arr[i] << "\t";
    cout << endl;
    return 0;
}
    
