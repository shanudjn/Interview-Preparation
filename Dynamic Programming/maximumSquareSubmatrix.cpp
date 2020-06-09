#include<iostream>
using namespace std;
#include<climits>


int findMaxSquareWithAllZeros(int **arr, int row, int col){
  int dp[row][col];
  //filling the fit row
  for(int j = 0; j<col; j++){
    dp[0][j] = arr[0][j];
  }

  //filling the first column
  for(int i = 0; i <row; i++){
    dp[i][0] = arr[i][0];
  }

  //remaining cells checking
  for(int i = 1; i < row; i++){
    for(int j = 1; j < col; j++){
      if(arr[i][j] == 0){
        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
      }
      else{
        dp[i][j] = 0;
      }
    }
  }

  //finding the largest number
  int ans = INT_MIN;
  for(int i = 0 ; i < row; i++){
    for(int j = 0; j < col; j++){
      if(dp[i][j]>ans){
        ans = dp[i][j];
      }
    }
  }
  return ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  int **arr = new int*[n];
  for(int i = 0 ; i < n; i++){
    arr[i] = new int[m];
    for(int j = 0 ; j < m; j++){
      cin >> arr[i][j];
    }
  }
  cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

}
