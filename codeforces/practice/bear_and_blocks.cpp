#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
const int inf = 1e9 + 5;

int t[nax], res[nax];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &t[i]);
	int worst = 0;
	for(int i = 1; i <= n; ++i) {
		worst = min(worst, t[i]-i);
		res[i] = i + worst;
        // printf("%d ",res[i]);
    }
    // printf("\n");
	worst = n + 1;
	for(int i = n; i >= 1; --i) {
		worst = min(worst, t[i]+i);
		res[i] = min(res[i], worst-i);
        // printf("%d ",res[i]);
	}
    // printf("\n");
	int R = 0;
	for(int i = 1; i <= n; ++i)
		R = max(R, res[i]);
	printf("%d\n", R);
	return 0;
}