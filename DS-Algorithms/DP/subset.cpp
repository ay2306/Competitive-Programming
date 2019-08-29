#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

bool **dp;


void display(const vector<int>& v)
{
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

void printAllSubsets(int arr[], int n, int k){
    if(n == 0 || sum < 0)return ;
    dp = new bool*[n];
    for(int i = 0; i < n; ++i){
        dp[i] = new bool[k+1];
        dp[i][0] = true;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = true;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= sum; ++j){
            dp[i][j] = (arr[i] <= j)?dp[i-1][j] || dp[i-1][j-arr[i]]: dp[i-1][j];
            
        }
    }

}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);
    return 0;
}