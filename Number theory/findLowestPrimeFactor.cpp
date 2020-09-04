//find lowest prime factor for every number from 1 to n

#include<iostream>
using namespace std;

void lowestPrimefactor(int n, int * p){
  p[0] = 1;
  p[1] = 1;
  for(int i = 2 ; i <= n; i++){
    if(p[i] == 0){

      for(int j = 1; i*j <= n; j++){
        if(p[i*j] == 0){
          p[i*j] = i;
        }
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  int * p = new int[n+1];
  for(int i = 0; i <= n; i++){
    p[i] = 0;
  }
  lowestPrimefactor(n,p);
  for(int i = 1; i <= n; i++){
    cout << i << " " << p[i] << endl;
  }

}
