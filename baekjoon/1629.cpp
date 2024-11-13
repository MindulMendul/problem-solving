#include <iostream>

using namespace std;

typedef long long int lli;

lli sol(lli a, lli b, lli c){
  if(b==0) return 1;
  if(b==1) return a%c;
  lli s=sol(a, b/2, c);
  return (b%2==0)?(s*s)%c:(((s*s)%c)*(a%c))%c;
}

int main(){
  lli A, B, C; cin>>A>>B>>C;
  cout<<sol(A,B,C);

  return 0;
}
