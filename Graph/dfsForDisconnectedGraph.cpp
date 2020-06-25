#include<iostream>
using namespace std;

void printDfs(int n, int **edges, int startingVertex, bool *visited){
  cout<<startingVertex << " ";
  visited[startingVertex] = true;
  for(int i = 0; i < n; i++){
    if(startingVertex == i){
      continue;
    }
    if(edges[startingVertex][i] == 1 && !visited[i]){
      //cout << i << " ";
      visited[i] = true;
      printDfs(n, edges, i, visited);
    }
  }
}

void dfs(int n, int **edges){
    bool *visited = new bool[n];
    for(int i = 0; i < n ; i++){
      visited[i] = false;
    }
    for(int i = 0 ; i < n ; i++){
      if(!visited[i]){
        printDfs(n, edges, i, visited);
      }
    }
}

int main(){
  int n, e;
  cin >> n >> e;

  int ** edges = new int*[n];
  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n ;j++){
      edges[i][j] = 0;
    }
  }

  for(int i = 0; i < e; i++){
    int s, f;
    cin >> s >>f;
    edges[s][f] = 1;
    edges[f][s] = 1;
  }

  dfs(n, edges);
}
