#include<iostream>
using namespace std;


void print(int **edges, int n, int startingVertex){
  cout << startingVertex << endl;
  visited[startingVertex] = true;

  for(int i = 0; i < n; i++){
    if(i == startingVertex){
      continue;
    }
    if(edges[startingVertex][i] == 1){
      if(visited[i] == true){
        continue;
      }
      print(edges, n, i, visited);
    }
  }
}

int main(){
  int n, e;
  cin >> n >> e;
  int **edges = new int*[n];
  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n; j++){
      edges[i][j] = 0;
    }
  }
  for(int i = 0 ; i < e; i++){
    int f,s;
    cin >> s >> f;
    edges[s][f] = 1;
    edges[f][s] = 1;
  }
  bool *visited = new bool[n];
  for(int i = 0 ; i < n; i++){
    visited[i] = false;
  }
  print(edges, n, 0, visited);

}
