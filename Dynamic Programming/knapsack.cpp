#include<iostream>
using namespace std;
#include<cmath>


int knapsack(int n, int *weights, int *values, int maxWeight ){
  //base case
  if( n == 0 || maxWeight == 0){
    return 0;
  }
  //corner case
  if(weights[0] > maxWeight){
    return knapsack(n-1, weights+1, values + 1, maxWeight);
  }

  //recursive call and small calculation
  int a = values[0] + knapsack(n-1, weights+1, values + 1, maxWeight - weights[0]);
  int b = knapsack(n-1, weights+1, values + 1, maxWeight);

  int ans = max(a, b);

  return ans;


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

  cout << knapsack(n, weights, values, maxWeight);

}
