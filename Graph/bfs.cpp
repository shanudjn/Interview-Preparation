#include<iostream>
using namespace std;
#include<queue>

void bfs(int n, int ** edges, bool *visited, int startingVertex){
  queue<int> pendingVertices;
  pendingVertices.push(startingVertex);
  visited[startingVertex] = true;
  while(pendingVertices.size() != 0){
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();
    cout << currentVertex << " ";
    for(int i = 0 ; i < n ; i++){
      if(i == currentVertex){
        continue;
      }
      if(edges[currentVertex][i]==1 && !visited[i]){
        pendingVertices.push(i);
        visited[i] = true;
      }
    }
  }
}

int main(){
  int n, e;
  cin >> n >> e;
  int ** edges = new int*[n];
  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0 ; j < n ; j++){
      edges[i][j] = 0;
    }
  }
  for(int i = 0; i< e; i++){
    int s, j;
    cin >> s >> j;
    edges[s][j] = 1;
    edges[j][s] = 1;
  }
  bool *visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
  }

  bfs(n, edges, visited, 0);

}
