#include<iostream>
using namespace std;
#include<climits>

int findMinVertex(bool * visited, int * distance, int n){
  int minVertex = -1;
  for(int i = 0; i < n; i++){
    if(!visited[i] && (minVertex==-1 || distance[i] < distance[minVertex])){
      minVertex = i;
    }
  }
  return minVertex;
}

void dijkstra(int ** edges, int n, int startVertex){
  int * distance = new int[n];
  bool * visited = new bool[n];
  for(int i = 0; i < n; i++){
    visited[i] = false;
    distance[i] = INT_MAX;
  }
  distance[startVertex] = 0;
  for(int i = 0; i < n; i++){
    int minVertex = findMinVertex(visited, distance, n);
    visited[minVertex] = true;
    for(int j = 0; j < n; j++){
      if(edges[minVertex][j] != 0 && !visited[j]){
        int dist = distance[minVertex] + edges[minVertex][j];
        if(dist < distance[j]){
          distance[j] = dist;
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << distance[i] << endl;
  }

}

int main(){
  int n, e;
  cin >> n >> e;
  int ** edges = new int*[n];

  for(int i = 0; i < n; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n ; j++){
      edges[i][j] = 0; ;
    }
  }

  for(int i = 0; i < e; i++){
    int s, f, w;
    cin >> s >> f >> w;
    edges[s][f] = w;
    edges[f][s] = s;
  }
  int startVertex;
  cin >> startVertex;
  dijkstra(edges, n, startVertex);
}
