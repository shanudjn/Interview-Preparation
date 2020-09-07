#include<iostream>
using namespace std;


void sieve(int n, int *p){
   for(int i = 2; i <=n; i++){
     //if(p[i]==1){
       for(int j = 1; i*j <= n ;j++){
          p[i*j] = p[i*j] + 1;
       }
     //}
}
}

int main(){
  int a,b, n, count=0;
  cin >> a >> b >> n;
  int * p = new int[b+1];
  for(int i = 0; i <= b ; i++){
    p[i] = 1;
  }
  sieve(b, p);
  for(int i = a ; i <= b; i++){
    if(p[i]==n){
      count++;
    }
  }
  cout << count << endl;

}
