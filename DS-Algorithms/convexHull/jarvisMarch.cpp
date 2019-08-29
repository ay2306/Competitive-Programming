#include<bits/stdc++.h>
using namespace std;

class point{
public:
    int x;
    int y;
    point(){
        this->x = 0;
        this->y = 0;
    }
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
    bool operator==(const point &rhs){
        return (this->x == rhs.x && this->y == rhs.y);
    }
};

int crossProduct(point a, point b, point c){
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return (y2*x1 - x2*y1);
}

int distance(point a, point b, point c){
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return ((y1*y1 + x1*x1) - (x2*x2 - y2*y2));
}

bool equal(point a, point b){
    return (a.x == b.x && a.y == b.y);
}

bool comp(point a, point b){
    if(a.x < b.x)return true;
    if(a.x > b.x)return false;
    return (a.y < b.y);
}

vector<point> findConvexHull(vector<point> &points){
    point start = points[0];
    for(int i = 1; i < points.size(); ++i){
        if(points[i].x < start.x)start = points[i];
    }
    point current = start;
    vector<point> result;
    result.push_back(current);
    vector<point> collinear_points;
    while(true){
        point nextTarget = points[0];
        for(int i = 1; i < points.size(); ++i){
            if(points[i] == current)continue;
            int val;
            // Next line commented till crossProduct method is not defined
            val = crossProduct(current, nextTarget, points[i]);
            if(val > 0){
                nextTarget = points[i];
                collinear_points = vector<point> ();
            }else if(val == 0){
                if(distance(current, nextTarget, points[i]) < 0){
                    collinear_points.push_back(nextTarget);
                    nextTarget = points[i];
                }else{
                    collinear_points.push_back(points[i]);
                }
            }
        }
        for(point p: collinear_points){
            result.push_back(p);
        }
        if(nextTarget == start)break;
        result.push_back(nextTarget);
        current = nextTarget;
    }
    // sort(result.begin(),result.end(),comp);
    // point a = result[0];
    // vector<point> b;
    // b.push_back(a);
    // for(int i = 1; i < result.size(); ++i){
    //     if(equal(a,result[i]))continue;
    //     a = result[i];
    //     b.push_back(a);
    // }
    return result;
}


int main(){
    int n;
    cin >> n;
    vector<point> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].x >> p[i].y;
    }
    p = findConvexHull(p);
    for(auto i: p){
        printf("(%d, %d) ",i.x,i.y);
    }
    printf("\n");
    return 0;
}