//find prime numbers between 1 to N

//trick : at the beginning think every number is a prime number
#include<iostream>
using namespace std;

//p[i]= 0 -> prime
//p[i] = 1 -> not prime
int p[10];
void sieve(int n){
  p[0] = 1;
  p[1] = 1;
  for(int i = 2 ; i <=10; i++){
    if(p[i] == 0){
      for(int j = 2; i*j <= n; j++){
        p[i*j] = 1;
      }
    }
  }
}

int main(){

  int n;
  cin >> n;
  sieve(n);
  for(int i = 1; i <= n; i++){
    cout << i << " "<< p[i] << endl;
  }

}
