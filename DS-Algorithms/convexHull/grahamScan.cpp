#include<bits/stdc++.h>
using namespace std;

// struct point{
//     double x;
//     double y;
//     bool operator<(const point &rhs){
//         return ((this->x < rhs.x)|| (this->x == rhs.x && this->y < rhs.y));
//     }
// };
// vector<point> ans;
// //checking if orientation is clockwise
// bool cw(point &a, point &b, point &c){
//     return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
// }
// // checking if orientation is counter-clockwise
// bool ccw(point &a, point &b, point &c){
//     return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
// }

// void convex_hull(vector<point> &arr){
//     if(arr.size() == 1){
//         ans = vector<point> (1,arr[0]);
//         return ;
//     }
//     ans = vector<point> ();
//     sort(arr.begin(),arr.end());
//     point p1 = arr[0],p2 = arr.back();
//     vector<point> up,down;
//     up.emplace_back(p1);
//     down.emplace_back(p1);
//     for(int i = 1; i < (int)arr.size(); ++i){
//         if(i == arr.size()-1 || cw(p1,arr[i],p2)){
//             while(up.size() >= 2 && !cw(up[up.size()-2],up[up.size()-1],arr[i]))up.pop_back();
//             up.emplace_back(arr[i]);
//         }
//         if(i == arr.size()-1 || ccw(p1,arr[i],p2)){
//             while(down.size() >= 2 && !ccw(down[down.size()-2],down[down.size()-1],arr[i]))down.pop_back();
//             down.emplace_back(arr[i]);
//         }
//     }
//     for(auto &i: up)ans.emplace_back(i);
//     for(auto &i: down)ans.emplace_back(i);
// }

// int main(){

//     return 0;
// }

class Solution {
public:
    struct point{
        int x;
        int y;
        point(){}
        point(int x,int y){
            this->x=x;
            this->y=y;
        }
        bool operator<(const point &rhs){
            return ((this->x < rhs.x)|| (this->x == rhs.x && this->y < rhs.y));
        }
    };
    vector<vector<int>> ans;
    //checking if orientation is clockwise
    bool cw(point &a, point &b, point &c){
        return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
    }
    // checking if orientation is counter-clockwise
    bool ccw(point &a, point &b, point &c){
        return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
    }

    void convex_hull(vector<point> &arr){
        ans = vector<vector<int>> ();
        if(arr.size() == 1){
            ans.emplace_back(vector<int> (2));
            ans[0][0] = arr[0].x;
            ans[0][1] = arr[0].y;
            return ;
        }
        sort(arr.begin(),arr.end());
        point p1 = arr[0],p2 = arr.back();
        vector<point> up,down;
        up.emplace_back(p1);
        down.emplace_back(p1);
        for(int i = 1; i < (int)arr.size(); ++i){
            if(i == arr.size()-1 || cw(p1,arr[i],p2)){
                while(up.size() >= 2 && !cw(up[up.size()-2],up[up.size()-1],arr[i]))up.pop_back();
                up.emplace_back(arr[i]);
            }
            if(i == arr.size()-1 || ccw(p1,arr[i],p2)){
                while(down.size() >= 2 && !ccw(down[down.size()-2],down[down.size()-1],arr[i]))down.pop_back();
                down.emplace_back(arr[i]);
            }
        }
        for(auto &i: up){vector<int> p; p.emplace_back(i.x); p.emplace_back(i.y); ans.emplace_back(p);}
        if(down.size() > 2){
            down.pop_back();
            down.pop_back();
            reverse(down.begin(),down.end());
            for(auto &i: down){vector<int> p; p.emplace_back(i.x); p.emplace_back(i.y); ans.emplace_back(p);}
        }
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<point> arr;
        for(auto &i: points){
            arr.emplace_back(point(i[0],i[1]));
        }
        for(auto &i: arr){
            cout << "(" << i.x << ", " << i.y << ")  ";
        }
        cout << endl;
        convex_hull(arr);
        return ans;
    }
};