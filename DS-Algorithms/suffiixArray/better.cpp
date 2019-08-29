#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

struct suffix{
    int rank[2];
    int index;
};

int cmp(struct suffix a, struct suffix b){
    return (a.rank[0] == b.rank[0])?(a.rank[1] < b.rank[1]? 1 : 0):(a.rank[0] < b.rank[0]? 1 : 0);
}

int* buildSuffixArray(char* txt, int n){
    struct suffix suffixes[n];
    for(int i = 0; i < n; ++i){
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)?(txt[i+1] - 'a'):-1;
     }
    int *ind = new int[n];
    sort(suffixes,suffixes+n,cmp);
    for(int k = 4; k < 2*n; k*=2){
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        for(int i = 1; i < n; ++i){
            if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
                suffixes[i].rank[0] = rank;
            }
            else{
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        for(int i = 0; i < n; ++i){
            int nextIndex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextIndex < n)?suffixes[ind[nextIndex]].rank[0]:-1;
        }
        sort(suffixes,suffixes+n,cmp);
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++)arr[i] = suffixes[i].index;
 
    return arr;
}

void patSearch(char *pat, char *txt, int *suffArr, int n)
{
    int m = strlen(pat);
 
    int l = 0, r = n-1; 
    int c = 0;
    while (l <= r)
    {
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);
 
        if (res == 0)
        {
            // cout << "Pattern found at index " << suffArr[mid];
            c++;
        }
 
        if (res < 0) r = mid - 1;
 
        else l = mid + 1;
    }
    cout << c << endl;
}

int main(){
    char txt[1000],p[100];
    cin >> txt >> p;
    int n = strlen(txt);
    int *arr = buildSuffixArray(txt,n);
    patSearch(p,txt,arr,n);
    // for(int i = 0; i < n; ++i){
    //     cout << (txt+arr[i]) << endl;
    //     // cout << arr[i] << " ";
    // }
    // cout << endl;
}