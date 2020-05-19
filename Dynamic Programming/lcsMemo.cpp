#include<iostream>
using namespace std;
#include<climits>
#include<string>

int lcsMemo(string s, string t, int **output){
  int m = s.size();
  int n = t.size();
  //base case
  if(s.size() == 0 || t.size() == 0){
    return 0;
  }
  //check if the answer is already present
  if(output[m][n] != -1){
    return output[m][n];
  }
  //recursive calls
  int ans;
  if(s[0] == t[0]){
     ans = 1 + lcsMemo(s.substr(1), t.substr(1), output);
  }
  else{
    int a = lcsMemo(s.substr(1), t, output);
    int b = lcsMemo(s, t.substr(1), output);
    int c = lcsMemo(s.substr(1), t.substr(1), output);
    ans = max(a, max(b, c));

  }
  //save the answer
  output[m][n] = ans;
  return ans;
}

int lcsMemo(string s, string t){
  int m = s.size();
  int n = t.size();
  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n+1];
    for(int j = 0; j <=n; j++){
      output[i][j] = -1;
    }
  }
  return lcsMemo(s, t, output);


}

int main(){
  string s, t;
  cin >> s >> t;
  cout << lcsMemo(s, t) << endl;
}
