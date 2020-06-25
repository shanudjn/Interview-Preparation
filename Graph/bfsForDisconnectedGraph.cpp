#include<iostream>
using namespace std;
#include<queue>


void printBfs(int n, int **edges, int startingVertex, bool *visited){
  queue<int> pendingVertices;
  pendingVertices.push(startingVertex);
  visited[startingVertex] = true;
  while(!pendingVertices.empty()){
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();
    cout << currentVertex << " ";
    for(int i = 0 ; i < n ; i++){
      if(i == currentVertex){
        continue;
      }
      if(edges[currentVertex][i] == 1 && !visited[i]){
        pendingVertices.push(i);
        visited[i] = true;
      }

    }
  }
}

void bfs(int n, int **edges){
  bool *visited = new bool[n];
  for(int i = 0 ; i < n; i++){
    visited[i] = false;
  }
  for(int i = 0 ; i < n ; i++){
    if(!visited[i]){
      printBfs(n, edges, i, visited);
    }
  }
}

int main(){
  int n, e;
  cin >> n >> e;

  //adjacency matrix
  int **edges = new int*[n];
  for(int i = 0; i<n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n; j++){
      edges[i][j] = 0;
    }
  }

  //taking input for the nodes that are connected to each other through e number of edges
  for(int i = 0; i < e; i++){
    int s, f;
    cin >> s >>f;
    edges[s][f] = 1;
    edges[f][s] = 1;
  }
  bfs(n, edges);
}
