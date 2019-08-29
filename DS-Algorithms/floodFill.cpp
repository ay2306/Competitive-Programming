#include<iostream>
using namespace std;

bool DFS(int x, int y, bool visited[11][11], int arr[11][11], int n, int m, int dest_x, int dest_y){
    if(x == dest_x && y == dest_y)return true;
    if(x >= n || y >= m)return false;
    if(x < 0 || y < 0)return false;
    if(visited[x][y])return false;
    if(arr[x][y] == 0)return false;
    visited[x][y] = true;  
    if(DFS(x+1,y,visited,arr,n,m,dest_x,dest_y)==true)return true;
    if(DFS(x-1,y,visited,arr,n,m,dest_x,dest_y)==true)return true;
    if(DFS(x,y+1,visited,arr,n,m,dest_x,dest_y)==true)return true;
    if(DFS(x,y-1,visited,arr,n,m,dest_x,dest_y)==true)return true;
    return false;
    
}

int main(){
    int n,m,a;
    cin >> n >> m;
    int arr[11][11];
    bool visited[11][11];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
                visited[i][j]=false;}
    }
    if(DFS(0,0,visited,arr,n,m,n-1,m-1))cout << "Yes";
    else{cout << "No";}
}
