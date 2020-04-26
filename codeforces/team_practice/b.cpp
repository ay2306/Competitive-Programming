#include<bits/stdc++.h>
using namespace std;
int main(){
    int x1,x2,y1,y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2 && y1 == y2)return cout << "0 0 0\n",0;
    int g,r = (x1!=x2) + (y1!=y2), k = abs(x1-x2)+abs(y2-y1)-min(abs(x1-x2),abs(y2-y1));
    if((x1+y1)%2 == (x2+y2)%2)g = 2- (abs(x1-x2)==abs(y1-y2));
    else g = 0;
    return cout << r << " " << g << " " << k,0;
}