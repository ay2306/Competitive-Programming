#include<bits/stdc++.h>
using namespace std;

struct line{
	int dx,dy,c;
	line(){}
	line(int x1, int y1, int x2, int y2):dx(x1-x2),dy(y1-y2){}
	void normalize(){
		if(dy < 0)dy=-dy,dx=-dx;
	}
	bool parallel(const line &rhs)const{
		rhs.normalize();
		normalize();
		return dy == rhs.dy && dx == rhs.dx;
	}
	pair<double,double> intersectingPoint(const line &rhs){
		pair<double,double> ans;
		
	}
};

int solve(){
	double x[4],y[4];
	for(int i = 0; i < 4; ++i)cin >> 

	return 0;
}

int main(){
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
