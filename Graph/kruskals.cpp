#include<iostream>
using namespace std;
#include<algorithm>

class Edge{
public:
  int source;
  int destination;
  int weight;
};


bool compare(Edge e1, Edge e2){

    return e1.weight < e2.weight;

}

int findParent(int vertex, int * parents){
  if(parents[vertex] == vertex){
    return vertex;
  }
  return findParent(parents[vertex], parents);
}


void kruskals(Edge *input, int n, int E){
  sort(input, input+E, compare);

  Edge* output = new Edge[n-1];

  int *parents  = new int[n];
  for(int i = 0; i < n; i++){
    parents[i] = i;
  }

  int count = 0;
  int i = 0;
  while(count != n-1){
    Edge currentEdge = input[i];

    int sourceParent = findParent(currentEdge.source, parents);
    int destParent = findParent(currentEdge.destination, parents);

    if(sourceParent != destParent){
      output[count] = currentEdge;
      count++;
      parents[sourceParent] = destParent;
    }
    i++;
  }
  for(int i = 0; i < n-1; i++){
    cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
  }

}


int main(){
  int n, E;
  cin >> n >> E;

  Edge *input = new Edge[E];
  for(int i = 0; i < E; i++){
    int s, d, w;
    cin >> s >> d >> w;
    input[i].source = s;
    input[i].destination = d;
    input[i].weight = w;
  }

  kruskals(input, n, E);

}
