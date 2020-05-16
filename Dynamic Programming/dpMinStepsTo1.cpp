#include<iostream>
using namespace std;
#include<climits>
#include<cmath>


int minStepsToOneHelper(int *arr, int n){
  //base case
  int y = INT_MAX, z = INT_MAX;
  if(n <= 1){
    arr[n] = 0;
    return arr[n];
  }
  if(arr[n] != -1){
    return arr[n];
  }
  int x = minStepsToOneHelper(arr, n - 1);
  if(n%2 == 0){
    y = minStepsToOneHelper(arr,n / 2);
  }
  if(n%3 == 0){
    z = minStepsToOneHelper(arr,n / 3);
  }
  int ans = min(min(x, y), z) + 1;
  arr[n] = ans;
  return arr[n];

}
int minCountToOne(int n){
  int *ans = new int[n+1];
  for(int i = 0 ; i < n+1; i++){
    ans[i] = -1;
  }
  minStepsToOneHelper(ans, n);
}

int main(){
  int n;
  cin >> n;
  int minCount = minCountToOne(n);
  cout << minCount;
}
