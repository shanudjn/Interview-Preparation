#include<iostream>
using namespace std;
#include<climits>
#include<string>

int lcs(string s, string t){
  //base case
  if(s[0] == '\0' || t[0]=='\0'){
    return 0;
  }
  //recursice call
  if(s[0] == t[0]){
    return 1 + lcs(s.substr(1), t.substr(1));
  }
  else{
    int x = lcs(s, t.substr(1));
    int y = lcs(s.substr(1), t);
    int z = lcs(s.substr(1), t.substr(1));

    int ans  = max(x, max(y, z));
    return ans;
  }

}
int main(){
  string s, t;
  cin >> s >> t;
  cout << lcs(s, t) << endl;
}
