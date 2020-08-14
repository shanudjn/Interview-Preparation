#include<iostream>
using namespace std;
#include<vector>

vector<int> * getIslandsHelper(int n, int sv, int ** edges, bool * visited){
  vector<int> * output = new vector<int>();
  visited[sv] = true;
  output->push_back(sv);
  for(int i = 0; i < n; i++){
    if(edges[sv][i] == 1 && !visited[i]){
      visited[i] = true;
      output->push_back(i);
    }
  }
  return output;
}


int getNumberOfConnectedIslands(int n, int m, vector<int> u, vector<int> v){
  //creating adjacency matrix
  int ** edges = new int*[n];
  for(int i = 0 ; i < n ; i++){
    edges[i] = new int[n];
    for(int j = 0; j < n ; j++){
      edges[i][j] = 0;
    }
  }
  //initialize adjacency matrix
  for(int i = 0; i < m; i++){
    edges[u[i]-1][v[i]-1] = 1;
    edges[v[i]-1][u[i]-1] = 1;
  }
  //initialize visited array
  bool *visited = new bool[n];
  for(int i = 0 ; i < n; i++){
    visited[i] = false;
  }
  int count = 0;
  vector<int> * output = new vector<int>();
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      output = getIslandsHelper(n,i,edges, visited);
      count++;      
    }
  }
  return count;
}

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> u, v;
  for(int i = 0; i < m; i++){
    int num ;
    cin >> num;
    u.push_back(num);
  }

  for(int i = 0; i < m; i++){
    int num ;
    cin >> num;
    v.push_back(num);
  }

  // for(int i = 0 ; i < m; i++){
  //   cout << u[i] <<" "<< v[i] << endl;
  // }
  cout << getNumberOfConnectedIslands(n,m, u, v) << endl;
}
