#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include <unordered_map>

vector<int> * getPathbfsHelper(int ** edges, int v, int sv, int ev, bool * visited){
  queue<int> pendingVertices;
  unordered_map<int,int> umap;
  vector<int> * output = new vector<int>();


  pendingVertices.push(sv);
  visited[sv] = true;
  while(pendingVertices.size() != 0){
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();

    for(int i = 0; i < v; i++){
      if(edges[currentVertex][i] == 1 && !visited[i]){
        if(i == ev){
          umap[i] = currentVertex;
          int key = ev;
          output->push_back(key);
          while(key != sv){
          //  output->push_back(key);
            key = umap[key];
            output->push_back(key);
          }
          if(output!= NULL){
            return output;
          }
          else{
            return NULL;
          }
        }
        else{
          pendingVertices.push(i);
          umap[i] = currentVertex;
          visited[i] = true;
        }
      }
    }
  }


}

vector<int> * getPathbfs(int ** edges, int v, int sv, int ev ){
  bool * visited = new bool[v];
  for(int i = 0; i < v; i++){
    visited[i] = false;
  }
  vector<int> * output = getPathbfsHelper(edges, v, sv, ev, visited);
  delete [] visited;
  return output;
}

int main(){
  int v, e;
  cin >> v >> e;

  int ** edges = new int*[v];
  for(int i = 0; i < v; i++){
    edges[i] = new int[v];
    for(int j = 0; j < v ;j++){
      edges[i][j] = 0;
    }
  }

  for(int i = 0 ; i < e; i++){
    int s, f;
    cin >> s >> f;
    edges[s][f] = 1;
    edges[f][s] = 1;
  }
  int start, end;
  cin >> start >> end;

  vector<int> *output = getPathbfs(edges, v, start, end);
  if(output != NULL){
    for(int i = 0 ; i < output->size(); i++){
      cout<<output->at(i) << endl;
    }
  }
  else{
    cout << "Not path" ;
  }
}
