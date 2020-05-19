#include<iostream>
using namespace std;
#include<string>
#include<cmath>


int editDistanceMemo(string s, string t, int **output){
  int m = s.size();
  int n = t.size();
  //base case
  if(s.size() == 0 || t.size() == 0){
    return max(s.size(), t.size());
  }
  //check if answer already exist
  if(output[m][n] != -1){
    return output[m][n];
  }
  //recursive call and small calculation
  int ans;
  if(s[0] == t[0]){
    ans = editDistanceMemo(s.substr(1), t.substr(1), output);
  }
  else{
    int a = 1 + editDistanceMemo(s.substr(1), t, output);
    int b = 1 + editDistanceMemo(s, t.substr(1), output);
    int c = 1 + editDistanceMemo(s.substr(1), t.substr(1), output);
    ans = min(a, min(b, c));
  }
  output[m][n] = ans;
  return ans;

}

int editDistanceMemo(string s, string t){
  int m = s.size();
  int n = t.size();
  int **output = new int*[m + 1];
  for(int i = 0 ; i <= m; i++){
    output[i] = new int[n + 1];
    for(int j = 0 ; j <= n; j++){
      output[i][j] = -1;
    }
  }
  return editDistanceMemo(s, t, output);
}
int main(){
  string s, t;
  cin >> s >> t;
  cout << editDistanceMemo(s, t) << endl;
}
