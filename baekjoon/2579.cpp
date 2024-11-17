#include <iostream>

using namespace std;

int N;
int stair[300];
int mem[300];

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //init
  cin>>N;
  for(int i=0; i<N; i++){cin>>stair[i]; mem[i]=0;}

  //calculate
  mem[0]=stair[0];
  mem[1]=stair[0]+stair[1];
  mem[2]=stair[0]+stair[2]>stair[1]+stair[2]?stair[0]+stair[2]:stair[1]+stair[2];
  if(N<3) cout<<mem[N-1]; // 혹시 N<3 이면 이미 구한 걸로 끝
  else {
    for(int i=3; i<N; i++){
      int case1, case2;
      case1=stair[i]+mem[i-2];
      case2=stair[i]+stair[i-1]+mem[i-3];
      mem[i]=case1>case2?case1:case2;
    }
    cout<<mem[N-1];
  }
  
  return 0;
}
