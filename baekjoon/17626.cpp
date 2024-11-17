#include <iostream>
#include <cmath>

using namespace std;

int mem[224];

int search(int n1){
  // 1
  if(n1==mem[(int)floor(sqrt(n1))]) return 1;

  // 2
  for(int i1=floor(sqrt(n1)); i1>0; i1--){
    int n2=n1-mem[i1]; if(n2<=0) continue; 
    if(n2==mem[(int)floor(sqrt(n2))]) return 2;
  }

  for(int i1=floor(sqrt(n1)); i1>0; i1--){
    int n2=n1-mem[i1]; if(n2<=0) continue; 
    for(int i2=floor(sqrt(n2)); i2>0; i2--){
      int n3=n2-mem[i2]; if(n3<=0) continue; 
      if(n3==mem[(int)floor(sqrt(n3))]) return 3; // 3
    }
  }

  // 4
  return 4;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  // init
  int N, i; cin>>N;
  for(i=0; i<224; i++){
    mem[i]=i*i;
  }

  //calculate
  cout<<search(N);
 
  return 0;
}
