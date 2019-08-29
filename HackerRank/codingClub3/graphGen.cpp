#include<bits/stdc++.h>
#define MAX_VERTICES 100000
#define RUN 1 
#define FILE_READ freopen("input.txt","w",stdout);

// Define the maximum number of edges 
#define MAX_EDGES 100000
#define MAX_QUERIES 100
  
using namespace std;
int main() 
{ 
    FILE_READ
    set<pair<int, int> > container; 
    set<pair<int, int> >::iterator it; 
      
    // Uncomment the below line to store 
    // the test data in a file 
    // freopen ("Test_Cases_Directed_Unweighted_Graph.in", "w", stdout); 
      
    //For random values every time 
    srand(time(NULL)); 
      
    int NUM;    // Number of Vertices 
    int Q;    // Number of Vertices 
    int NUMEDGE; // Number of Edges 
      
    for (int i=1; i<=RUN; i++) 
    { 
        NUM = 1 + rand() % MAX_VERTICES; 
        Q = 1 + rand() % MAX_QUERIES; 
      
        // Define the maximum number of edges of the graph 
        // Since the most dense graph can have N*(N-1)/2 edges 
        // where N =  nnumber of vertices in the graph 
        NUMEDGE = 1 + rand() % MAX_EDGES; 
          
        while (NUMEDGE > NUM*(NUM-1)/2) 
                NUMEDGE = 1 + rand() % MAX_EDGES;         
          
        // First print the number of vertices and edges 
        printf("%d %d\n", NUM, NUMEDGE); 
          
        // Then print the edges of the form (a b) 
        // where 'a' is connected to 'b' 
        for (int j=1; j<=NUMEDGE; j++) 
        { 
            int a = 1 + rand() % NUM; 
            int b = 1 + rand() % NUM; 
            pair<int, int> p = make_pair(a, b); 
              
            // Search for a random "new" edge everytime 
            // Note - In a tree the edge (a, b) is same  
            // as the edge (b, a) 
            while (container.find(p) != container.end()) 
            { 
                a = 1 + rand() % NUM; 
                b = 1 + rand() % NUM; 
                p = make_pair(a, b); 
            } 
            container.insert(p); 
        } 
              
        for (it=container.begin(); it!=container.end(); ++it) 
            printf("%d %d\n", it->first, it->second); 
              
        container.clear(); 
        printf("\n");             
        printf("%d\n",Q);
        while(Q--){
            int a = 1 + rand() % NUM; 
            int c = 1 + rand() % NUM; 
            int b;
            do{
                b= 1 + rand() % NUM; 
            }while(b == a || b == c);
            printf("%d %d %d\n",a,b,c);
        }
      
    } 
    // Uncomment the below line to store 
    // the test data in a file 
    // fclose(stdout); 
    return(0); 
} 