#include<iostream>
#include<cmath>
using namespace std;
//using memoization
int minCountHelper(int *arr, int n){
  //base case
  if(n<=3){
    return n;
    arr[n] = n;
  }
  //check if answer exist
  if(arr[n] != -1){
    return arr[n];
  }
  for(int i = 1; i <= n ; i++){
    int x = i * i;
    int res = n;
    if(x == n){
      arr[n] = 1;
      return arr[n];
    }
    else{
      int ans = 1 +  minCountHelper(arr, n - x);
      arr[n] = min(ans, res);

    }

  }
  return arr[n];

}

int minCount(int n){
  int *arr = new int[n+1];
  for(int i = 0; i <= n; i++){
    arr[i] = -1;
  }
  minCountHelper(arr, n);
}

int main(){
  int n;
  cin >> n;
  cout << minCount(n) << endl;
}
