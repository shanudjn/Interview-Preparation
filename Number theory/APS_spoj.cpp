#include<iostream>
using namespace std;

// int p[10000000];
// int q[10000000];

void sieve(int n, int* p)
{
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
  int t;
  cin >> t;
  for(int i = 0 ; i < t; i++){
    int n;
    cin >> n;
    int * p = new int[n+1];
    int * q = new int[n+1];

    for(int i = 0; i <= n; i++){
      p[i] = 0;
    }
    sieve(n, p);
    // for(int i = 0; i <= n; i++){
    //   cout << i << p[i] << endl;
    // }
    q[0] = q[1] = 0;
    for(int j = 2; j <= n; j++){
      q[j] = q[j-1] + p[j];
    }
    cout << q[n] << endl;
  }
}
