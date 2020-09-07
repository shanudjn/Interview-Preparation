#include<iostream>
using namespace std;


void sieve(int n, int * p){
  p[0] = 1;
  p[1] = 1;
  for(int i = 2; i <= n; i++){
    if(p[i] == 1){
      for(int j = 2; i*j <=n ; j++){
        p[i*j] = p[i*j]+i;
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  int * p = new int[n+1];
  for(int i = 0 ; i <= n ; i++){
    p[i] = 1;
  }
  sieve(n, p);
  int * q = new int[n+1];
  q[0]=q[1]=0;

  for(int j = 2; j <=n ;j++){
    q[j] = q[j-1] + p[j];
  }
  cout << q[n];
}
