#include<iostream>
using namespace std;

int phi[1000004];

int etf(){
  phi[1] = 1;
  for(int i = 2; i <= 10000; i++){
    phi[i] = i;
  }
  for(int i = 2; i <= 10000; i++){
    if(phi[i] == i){
      int j = 1;
      while (i*j <= 10000) {
        phi[i*j] = phi[i*j]-(phi[i*j] / i);
        j++;
      }
    }
  }
}

int main(){
  etf();
  int n;
  cin >> n;
  cout << phi[n] << endl;
}
