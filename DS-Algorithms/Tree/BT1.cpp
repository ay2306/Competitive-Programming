/*


0 1 2 3 4 5 6
1 2 3 3 3 5 8

beg = 0 end = 6 mid = 3 arr[mid] = 3 matched thus
beg = 4 end = 6 mid = 5 arr[mid] = 5 (arr[mid]>element) thus
beg = 4 end = 4 mid = 4 arr[mid] = 3 matched

*/

#include<bits/stdc++.h>
using namespace std;
//program to find how many times a number occurs
int BinarySearch(vector<int> arr,int element,int beg,int endp,bool flag)
{
    int mid,result=-1;
    while(beg<=endp)  //condition for loop
    {
        mid=(endp+beg)/2;//equivalent to (beg+endp)/2

        if(element==arr[mid])
        {
            result=mid;
            if(flag)  //to find first occurence of the element
            {
                endp=mid-1;
            }
            else{   //to find last occurence of the element
                beg=mid+1;
            }
         }
        else if(element>arr[mid])
        {
           beg=mid+1;
        }
        else
        {
           endp=mid-1;
        }
    }
    return result;
}
int main()
{
    int index2,n,element;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>element;
    int index1=BinarySearch(arr,element,0,n-1,true); //calling function to get the first occurence
    if(index1==-1)
    {
        cout<<"element is not in the list\n";
    }
    else
    {
        index2=BinarySearch(arr,element,0,n-1,false); //calling function to get the last element
        cout<<index2-index1+1;  //no of times a number is occuring
    }
    return 0;
}

