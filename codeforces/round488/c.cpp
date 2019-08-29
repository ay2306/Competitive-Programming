#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;
 
int main(){
    bool pos = false;
    pair<int,int> s1[4],s2[4];
    pair<float,float> rs1[4],rs2[4];
    int x1min = INT_MAX;
    int y1min = INT_MAX;
    float x2min = INT_MAX;
    float y2min = INT_MAX;
    int x1max = INT_MIN;
    int y1max = INT_MIN;
    float x2max = INT_MIN;
    float y2max = INT_MIN;
    pair<float,float> c1,c2;
    for(int i = 0; i < 4; ++i){
        int a,b;
        cin >> a >> b;
        s1[i] = mp(a,b);
        if(a > x1max)x1max = a;
        if(a < x1min)x1min = a;
        if(b > y1max)y1max = b;
        if(b < y1min)y1min = b;
        rs1[i] = mp(float(a+b)/sqrt(2),float(b-a)/sqrt(2));
    }
    for(int i = 0; i < 4; ++i){
        int a,b;
        cin >> a >> b;
        s2[i] = mp(a,b);
        rs2[i] = mp(float(a+b)/sqrt(2),float(b-a)/sqrt(2));;
        if(rs2[i].first > x2max)x2max = rs2[i].first;
        if(rs2[i].first < x2min)x2min = rs2[i].first;
        if(rs2[i].second > y2max)y2max = rs2[i].second;
        if(rs2[i].second < y2min)y2min = rs2[i].second;
    }
    c1.first = ((rs1[0].first + rs1[2].first)/float(2));
    c1.second = ((rs1[0].second + rs1[2].second)/float(2));
    c2.first = ((s2[0].first + s2[2].first)/float(2));
    c2.second = ((s2[0].second + s2[2].second)/float(2));
    if(c2.first >= float(x1min) && c2.first <= float(x1max) ){
        if(c2.second >= float(y1min) && c2.second <= float(y1max) )
        {
            // cout << s2[0].first << " " << s2[0].second << "\n";
            // cout << s2[2].first << " " << s2[2].second << "\n";
            // cout << c2.first << " " << c2.second << "\n";
            // cout << "Case 1\n";
            pos = true;
            // break;
        }
    }
    if(c1.first >= float(x2min) && c1.first <= float(x2max) ){
        if(c1.second >= float(y2min) && c1.second <= float(y2max) )
        {
            // cout << "Case 2\n";
            pos = true;
            // break;
        }
    }
    for(int i = 0; i < 4 ; ++i){
        if(s2[i].first >= x1min && s2[i].first <= x1max ){
            if(s2[i].second >= y1min && s2[i].second <= y1max )
            {
                // cout << "Case 3\n";
                pos = true;
                break;
            }
        }
    }
    for(int i = 0; i < 4 ; ++i){
        if(rs1[i].first >= x2min && rs1[i].first <= x2max ){
            if(rs1[i].second >= y2min && rs1[i].second <= y2max )
            {
                // cout << "Case 4\n";                
                pos = true;
                break;
            }
        }
    }
    
    if(pos)cout << "YES";
    else cout << "NO";
    return 0;
}