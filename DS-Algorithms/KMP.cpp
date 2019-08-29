#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char *pat, int M, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];  
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt){
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = new int[M];
    computeLPSArray(pat,M,lps);
    int i = 0;
    int j = 0;
    while(i < N){
        if(pat[j] == txt[i]){
            ++i;
            ++j;
        }
        if(j == M){
            cout << "Pattern found at " << (i-j) << " index";
            j = lps[j-1];
        }else if(i < N && pat[j]!=txt[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
    char txt[1000], pat[1000];
    cin >> txt;
    cin >> pat;
    KMPSearch(pat,txt);
    return 0;
}