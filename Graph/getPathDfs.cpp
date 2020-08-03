#include<iostream>
using namespace std;
#include<vector>

vector<int> * getPathHelper(int **edges, int v, int sv, int ev, bool * visited){
  if(sv == ev){
    vector<int> * output = new vector<int>();
    output->push_back(ev);
    return output;
  }
  visited[sv] = true;
  for(int i = 0 ; i < v; i++){
    if(edges[sv][i] == 1 && !visited[i]){
      vector<int> * smallOutput = getPathHelper(edges,v, i, ev, visited);
      if(smallOutput != NULL){
        smallOutput->push_back(sv);
        return smallOutput;
      }
    }
  }
  return NULL;
}


vector<int> * getPath(int **edges, int v, int sv,int ev){
  bool *visited = new bool[v];
  for(int i = 0; i < v; i++){
    visited[i] = false;
  }
  vector<int> * output = getPathHelper(edges, v, sv, ev, visited);
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
  vector<int> * output = getPath(edges, v, start, end);
  if(output != NULL){
    for(int i = 0 ; i < output->size(); i++){
      cout<<output->at(i) << endl;
    }
  }
  else{
    cout << "Not path" ;
  }

}
