#include<iostream>
using namespace std;

int coinChange(int *denominations, int n, int v){
  //base case
  if(v == 0 || n == 0){
    return 0;
  }
  //recursive calculation
  int a = 1 + coinChange(denominations+1, n-1, v-denominations[0]);
  int b = coinChange(denominations, n-1, v);
  //small calc
  int ans = a+b;
  return ans;
}


int main(){
  int n , v;
  int *denominations =  new int[n];
  cin >> n;
  for(int i =0; i<n; i++){
    cin >> denominations[i];
  }
  cin >> v;
  cout << coinChange(denominations, n, v) << endl;
}
