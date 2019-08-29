#include<bits/stdc++.h>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;
// NAIVE ALGORITHM
/*
struct suffix{
	int index;
	char *suff;
};

int cmp(struct suffix a, struct suffix b){
	return (strcmp(a.suff,b.suff)<0)?1:0;
}

void suffixSearch(char *pat, char *txt, int *suffixArray, int n){
	int m = strlen(pat);
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = l + (r-l)/2;
		int res = strncmp(pat,txt+suffixArray[mid],m);
		if(res == 0){
			for(int i = 0; i < n; ++i){
				if(i>=suffixArray[mid] && i < suffixArray[mid]+m){
					char esc_char = 27;
					cout << esc_char << "[1m" << txt[i] << esc_char << "[0m";
				}else{
					cout << txt[i];
				}
			}
			return;
		}
		if(res<0)r = mid-1;
		else l = mid+1;
	}
	cout << "Pattern not found";
}

int *buildSuffixArray(char *txt, int n){
	struct suffix suffixes[n];
	for(int i = 0; i < n; ++i){
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}
	sort(suffixes,suffixes+n,cmp);
	int *suffixArray = new int[n];
	for(int i = 0; i < n; ++i){
		suffixArray[i] = suffixes[i].index;
	}
	return suffixArray; 
}

void printSuffixArray(int arr[], int n){
	for(int i = 0; i < n; ++i){
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char txt[] = "asfosaasdnfnafsdfsadf";
	int n = strlen(txt);
	int *suffixArray = buildSuffixArray(txt,n);
	//printSuffixArray(suffixArray, n);
	char pat[] = "nafs";
	suffixSearch(pat,txt,suffixArray,n);
	return 0;
}


*/

// ALGORITHM USING RANKS

struct suffix{
	int index;
	int rank[2];
};

int cmp(struct suffix a, struct suffix b){
	return (a.rank[0]==b.rank[0])?((a.rank[1]<b.rank[1])?1:0):((a.rank[0]<b.rank[0])?1:0);
}

int *buildSuffixArray(char *txt, int n){
	struct suffix suffixes[n];
	for(int i = 0; i < n; ++i){
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i]-'a';
		suffixes[i].rank[1] = ((i+1)<n)?(txt[i+1]-'a'):-1;
	} 
	sort(suffixes,suffixes+n,cmp);
	int ind[n];
	for(int k = 4; k < 2*n; k*=2;){
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		
	}
}