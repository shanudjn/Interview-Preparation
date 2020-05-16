#include<iostream>
using namespace std;

int fib_2(int n){
  //bottom-up approach also called dynamoc programming
  //this uses iterative approach
  int *ans = new int[n+1];
  ans[0] = 0;
  ans[1] = 1;
  for(int i=2; i<=n; i++){
    ans[i] = ans[i-1]+ans[i-2];
  }
  return ans[n];
}

int fib_helper(int n, int *arr){
  //top-down approach also called memoization
  //this uses recursive technique
  if(n <= 1){
    return n;
  }
  //check if output already exist
  if(arr[n] != -1){
    return arr[n];
  }
  int a = fib_helper(n-1, arr);
  int b = fib_helper(n-2, arr);

  arr[n] = a+b;
  return arr[n];

}


int fib(int n){
  int *arr = new int[n+1];
  for(int i = 0; i <= n; i++){
    arr[i] = -1;
  }
  return fib_helper(n, arr);
}

int main(){
  int n;
  cin >> n;
  cout << fib_2(n) << endl;
}
