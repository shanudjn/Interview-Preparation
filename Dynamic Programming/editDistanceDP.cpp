#include<iostream>
using namespace std;
#include<string>
#include<cmath>


int editDistanceDP(string s, string t){
  int m = s.size();
  int n = t.size();
  //output array
  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n+1];
  }
  //filling the first row
  for(int j = 0; j<=n; j++){
    output[0][j] = j;
  }
  //filling the first column
  for(int i = 0; i <= m; i++){
    output[i][0] = i;
  }
  //filling the remaining output array
  for(int  i = 1; i<=m; i++){
    for(int j = 1; j<=n; j++){
      if()
      output[i][j] = min(output[i-1][j], min(output[i][j-1], output[i-1][j-1]));
    }
  }
  return output[m][n];
}

int main(){
  string s, t;
  cin >> s >> t;
  cout << editDistanceDP(s, t) << endl;
}
