#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct bfs_info{
        vector<vector<int> > board;
        int x;
        int y;
        int s;
        bfs_info(const vector<vector<int> > &a, int b, int c, int d){
            board = a;
            x = b;
            y = c;
            s = d;
        }
    };
    string gen_string(vector<vector<int> > board){
        string res = "";
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j)res+=to_string(board[i][j]);
        }
        return res;
    }
    bool valid_move(int x, int y){
        if(x >= 0 && x < 2 && y >= 0 && y < 3)return true;
        return false;
    }

public:
    int slidingPuzzle(vector<vector<int> >& board) {
        queue<bfs_info> todo;
        unordered_set<string> done;
        done.insert(gen_string(board));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                if(board[i][j] == 0)todo.push(bfs_info(board,i,j,0));
            }
        } 
        vector<vector<int> > solved = {{1,2,3},{4,5,0}};
        vector<int> x_offset = {1,-1,0,0};
        vector<int> y_offset = {0,0,1,-1};
        while(!todo.empty()){
            auto& info = todo.front();
            if(info.board == solved)break;
            for(int i = 0; i < 4; ++i){
                int new_x = info.x + x_offset[i];
                int new_y = info.y + y_offset[i];
                if(valid_move(new_x,new_y)){
                    vector<vector<int> > new_board = info.board;
                    swap(new_board[info.x][info.y],new_board[new_x][new_y]);
                    string s = gen_string(new_board);
                    if(done.find(s) == done.end()){
                        todo.push(bfs_info(new_board,new_x,new_y,info.s+1));
                        done.insert(s);
                    } 
                }
            }
            todo.pop();
        }
        return (todo.empty()?-1:todo.front().s);
    }
};

int main(){
    vector<vector<int> > a(2,vector<int> (3));
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j)cin >> a[i][j];
    }
    Solution s;
    cout << s.slidingPuzzle(a) << endl;
}