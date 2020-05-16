#include<iostream>
using namespace std;
#include<cmath>


int dpBalancedBtsHelper(int h, int *arr){
  //base case
  if(h<=1){
    arr[h] = 1;
    return arr[h];
  }
  //check if the answer already exist in the ans dp arry
  if(arr[h]!=-1){
    return arr[h];
  }
  //small calculation
  int mod = (int)pow(10,9) + 7;
  int x = dpBalancedBtsHelper(h-1, arr);
  int y = dpBalancedBtsHelper(h-2, arr);


  int temp1 = (int)(((long)(x) * x) % mod);
  int temp2 = (int)((2 * ((long)(x) * y)) % mod);

  int ans = temp1 + temp2;
  arr[h] = ans;
  return arr[h];
}


int dpBalancedBts(int h){
  int *arr = new int[h+1];
  for(int i = 0 ; i <= h; i++){
    arr[i] = -1;
  }
  dpBalancedBtsHelper(h, arr);
}

int main(){
  int h;
  cin >> h;
  cout << dpBalancedBts(h) << endl;
}
