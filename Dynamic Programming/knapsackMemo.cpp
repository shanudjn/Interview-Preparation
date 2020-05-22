#include<iostream>
using namespace std;
#include<cmath>

int knapsackMemo(int n, int *weights, int *values, int maxWeight, int **output){
  int valuesSize, weightsSize = n;
  //base case
  if(n == 0 || maxWeight == 0){
    return 0;
  }
  //check if the answer already exists
  if(output[n][n] != -1){
    return output[n][n];
  }
  //recursive call along with small calculation
  int ans ;
  if(weights[0] > maxWeight){
    ans = knapsackMemo(n-1, weights + 1, values + 1, maxWeight, output);
    output[n][n] = ans;
    return ans;
  }
  int a = values[0] + knapsackMemo(n-1, weights + 1, values + 1, maxWeight - weights[0], output );
  int b = knapsackMemo(n-1, weights + 1, values + 1, maxWeight, output);
  ans  = max(a, b);
  output[n][n] = ans;
  return ans;
}


int knapsackMemo(int n, int *weights, int *values, int maxWeight){
  int ** output =  new int*[n+1];
  for(int i = 0; i <= n; i++){
    output[i] = new int[n];
    for(int j = 0; j<=n ; j++){
      output[i][j] = -1;
    }
  }
  return knapsackMemo(n, weights, values, maxWeight, output);

}

int main(){

  int n, maxWeight;
  cin >> n;
  int *weights = new int[n];
  for(int i = 0 ; i < n; i++){
    cin >> weights[i];
  }
  int *values = new int[n];
  for(int i = 0; i < n; i++){
    cin >> values[i];
  }
  cin >> maxWeight;

  cout << knapsackMemo(n, weights, values, maxWeight);
}
