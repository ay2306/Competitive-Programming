/*
*    Code Daily has given you an array of integers, nums and a target value T, find the number of ways that you can add and subtract the values in nums to add up to T.
*
*    Input Format:
*
*    First line of input contains an integer N, denoting number of members of array.
*    Second line of input contains an integer T, which denotes the target sum.
*    Third line of input contains N space separated integers which are members of array.
*
*    Output Format:
*    
*    Print the number of ways possible to perform the required task.
*
*    Sample Case:
*
*    Input:
*    5
*    3
*    1 1 1 1 1
*
*    Output:
*    5
*
*    Explanation:
*
*    There are 5 possibilities to make the sum to 3.
*    1 + 1 + 1 + 1 - 1
*    1 + 1 + 1 - 1 + 1
*    1 + 1 - 1 + 1 + 1
*    1 - 1 + 1 + 1 + 1
*    -1 + 1 + 1 + 1 + 1
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[1001];
    int n,t;
    cin >> n >> t;
    for(int i = 0; i < n; ++i)cin >> arr[i];
}
