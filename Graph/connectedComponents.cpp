#include<iostream>
using namespace std;
#include<vector>


vector<int>* getConnecteComponentsHelper(int ** edges, int v, int sv, bool * visited){
  visited[sv] = true;
  vector<int>* smallOutput = new vector<int>();
  smallOutput->push_back(sv);
  for(int i = 0; i < v;i++){
    if(edges[sv][i] == 1 && !visited[i]){
      visited[i] = true;
      //std::cout << i << '\n';
      smallOutput -> push_back(i);
    }
  }
  return smallOutput;
}

void getConnecteComponents(int ** edges, int v){
  bool * visited  = new bool[v];
  for(int i = 0; i < v ; i++){
    visited[i] = false;
  }
  vector<int> * output =  new vector<int>() ;
  for(int i = 0; i < v; i++){
    if(!visited[i]){
      output = getConnecteComponentsHelper(edges, v, i, visited);
      // return output;
      for(int i = 0; i < output->size(); i++){
        cout<< output->at(i) << " ";
      }
      cout << endl;

    }
  }

}

int main(){
  int e, v;
  cin >> v >> e;
  int **edges  =  new int *[v];
  for(int i = 0 ; i < v; i++){
    edges[i] = new int[v];
    for(int j = 0; j < v; j++){
      edges[i][j] = 0;
    }
  }
  for(int i = 0 ; i < e; i++){
    int s , f;
    cin >> s >> f;
    edges[s][f] = 1;
    edges[f][s] = 1;
  }
  getConnecteComponents(edges, v);
  // vector<vector<int> > components;
  // vector<int> * output = new vector<int>();
  // output = getConnecteComponents(edges, v);
  // components.push_back(output);
  //
  // for(int i = 0; i < components.size(); i++){
  //   for(int j = 0; j < components[i].size(); j++){
  //     cout << components[i][j] << " ";
  //   }
  //   cout << endl;
  // }




}
