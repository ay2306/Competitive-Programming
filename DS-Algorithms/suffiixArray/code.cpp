#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

struct suffix{
    char *suff;
    int index;
};

int cmp(struct suffix a, struct suffix b){
    return (strcmp(a.suff,b.suff) < 0)?1:0;
}

int* buildSuffixArray(char* txt, int n){
    struct suffix suffixes[n];
    int *arr = new int[n];
    for(int i = 0; i < n; ++i){
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
    sort(suffixes,suffixes+n,cmp);
    for(int i = 0; i < n; ++i){
        arr[i] = suffixes[i].index;
    }
    return arr;
}

int main(){
    char *txt = "banana";
    int n = strlen(txt);
    int *arr = buildSuffixArray(txt,n);
    for(int i = 0; i < n; ++i){
        cout << (txt+arr[i]) << endl;
        // cout << arr[i] << " ";
    }
    // cout << endl;
}