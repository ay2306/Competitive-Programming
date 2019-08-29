#include<iostream>
using namespace std;

int find_articulation_points(int adj[][], V){
    int count = 0;
    bool *visited = new bool[V];
    for(int i = 0; i < V; ++i){
        visited = false;
    }
    int initial_val = 0;
    for(int i = 0; i < V; ++i){
        if(!visited[i]){
            DFS(adj, V, visited, i);
            initial_val++;
        }
    }
    for(int i = 0; i < V; ++i){
        for(int j = 0; j < V; ++j){
            visited[j] = false;
            
        }
    }
}

int main(){
    
    return 0;
}
