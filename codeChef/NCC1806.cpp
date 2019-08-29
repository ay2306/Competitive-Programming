#include<bits/stdc++.h>
#define ll unsigned long long int
#define mod 1000000007
using namespace std;

float height(int r1, int r2, int x1, int x2){
	int d = x2-x1;
	if(d<0)d*=-1;
	float k1 = float(r1+r2+d);
	float k2 = float(r1+r2-d);
	float k3 = float(r1-r2+d);
	float k4 = float(r2-r1+d);
	float k = k1*k2*k3*k4;
	k = sqrt(k);
	k/=float(d);
return k;
}
bool external(int x1, int x2, int r1, int r2){
	if(r1>r2){
		swap(r1,r2);
		swap(x1,x2);
	}
	int left = x2-r2;
	int right = x2+r2;
	if(x1 >= left && x1 <= right)return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		float maxheight = 0;
		int n;
		cin >> n;
		int *x = new int[n];
		int *r = new int[n];
		for(int i = 0; i < n; ++i){
			cin >> x[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> r[i];
		}
		for(int i = 0; i < n; ++i){
			for(int j = i+1; j < n; ++j){
				int d = x[i]-x[j];
				if(d<0)d*=-1;
				int k = r[i]-r[j];
				if(k<0)k*=-1;
				if(r[i]+r[j] > d ){
					float y = height(r[i],r[j],x[i],x[j]);
					if(maxheight < y)maxheight = y;
				}
			}
		}
		maxheight/=2;
		printf("%.6f\n",maxheight);
		// cout << maxheight/2 <<endl;
	}
return 0;
}


