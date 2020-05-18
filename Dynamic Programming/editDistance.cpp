#include<iostream>
using namespace std;
#include<string>
#include<cmath>

int editDistance(string s, string t){
  //base case
  if(s.size() == 0 || t.size() == 0){
    return max(s.size(), t.size());
  }
  int ans ;
  if(s[0] == t[0]){
    ans = editDistance(s.substr(1), t.substr(1));
  }
  else{
    //insert
    int a = 1 + editDistance(s.substr(1), t);
    //remove
    int b = 1 + editDistance(s, t.substr(1));
    //
    int c = 1 + editDistance(s.substr(1), t.substr(1));

    ans = min(a, min(b,c));
  }
  return ans;
}


int main(){
  string s, t;
  cin >> s >> t;
  cout << editDistance(s, t)<<endl;
}
