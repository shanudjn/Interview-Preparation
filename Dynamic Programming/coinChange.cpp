#include<iostream>
using namespace std;

int coinChange(int *denominations, int n, int v){
  int **output = new int*[n+1];
  for(int i = 0; i<=n; i++){
    output[i] = new int[v];
  }
  //filling the first row
  for(int j = 0; j< v; j++){
    output[0][j] = 1;
  }

  //remaining cells
  for(int i = 1; i<=n; i++){
    for(int j = 0; j<v; j++){
      int x = (i - denominations[j] >= 0) ? output[i - denominations[j]][j] : 0;
      int y = (j>=1)? output[i][j-1] : 0;
      output[i][j] = x + y;
    }
  }
  return output[n][v-1];
}


int main(){
  int n , v;
  cin >> v;
  int *denominations = new int[v];
  for(int i =0; i<v; i++){
    cin >> denominations[i];
  }
  cin >> n;
  cout << coinChange(denominations, n, v) << endl;
}
