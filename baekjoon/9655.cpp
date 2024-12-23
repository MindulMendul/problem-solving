#include <iostream>

using namespace std;

bool vic[1001][2];
int N;

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N;

  // input
  vic[0][0]=0; vic[0][1]=1;
  vic[1][0]=1; vic[1][1]=0;
  vic[2][0]=0; vic[2][1]=1;
  vic[3][0]=1; vic[3][1]=0;

  for(int i=4; i<1000; i++){
    vic[i][0]=(vic[i-1][1]*vic[i-3][1]);
    vic[i][1]=(vic[i-1][0]*vic[i-3][0]);
  }

  if(vic[N][0]) cout<<"SK";
  else cout<<"CY";
  
  return 0;
}