#include<iostream>
using namespace std;
#include<climits>

int findMinVertex(int * weights, bool * visited, int n){
  int minVertex = -1;
  for(int i = 0 ; i <n; i++){
    if(!visited[i] &&(minVertex==-1 || weights[i] < weights[minVertex])){
      minVertex = i;
    }
  }
  return  minVertex;
}

void prims(int **edges, int n){
  int * weights = new int[n];
  int * parents = new int[n];
  bool * visited = new bool[n];

  for(int i = 0 ; i < n; i++){
    weights[i] = INT_MAX;
    visited[i] = false;
  }
  parents[0] = -1;
  weights[0] = 0;

  for(int i = 0; i < n; i++){
    int minVertex = findMinVertex(weights, visited, n);
    visited[minVertex] = true;
    for(int j = 0 ; j < n; j++){
      if(edges[minVertex][j] != 0 && !visited[j]){
        if(edges[minVertex][j] < weights[j]){
          weights[j] = edges[minVertex][j];
          parents[j] = minVertex;
        }
      }
    }
  }
  for(int i = 1 ; i < n ; i++){
    if(parents[i] < i) {
      cout << parents[i] << i << weights[i] << endl;
    }else{
      cout << i << parents[i] << weights[i] << endl;
    }
  }
}

int main(){
  int n, e;
  cin >> n >> e;
  int **edges  = new int*[n];
  for(int i = 0; i < n ;i++){
    edges[i] = new int[n];
    for(int j = 0; j < n; j++){
      edges[i][j] = 0;
    }
  }
  for(int i = 0; i < e; i++){
    int s, f, w;
    cin >> s >> f >> w;
    edges[s][f] = w;
    edges[f][s] = w;
  }

  prims(edges, n);

  for(int i = 0; i < n ; i++){
    delete [] edges[i];
  }
  delete [] edges;
}
