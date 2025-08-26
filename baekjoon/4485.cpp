#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[125][125];
int rupee[125][125];

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N; cin>>N;
  int tc=1;
  while(N>0){
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {cin>>map[i][j]; rupee[i][j]=MAX;}
    rupee[0][0]=map[0][0];
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
      int x=q.front().first, y=q.front().second;
      q.pop();
      for(int d=0; d<4; d++){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
        if(rupee[yy][xx]<=map[yy][xx]+rupee[y][x]) continue;
        
        rupee[yy][xx]=map[yy][xx]+rupee[y][x];
        q.push(make_pair(xx,yy));
      }
    } 
    cout<<"Problem "<<tc++<<": "<<rupee[N-1][N-1]<<'\n';
    cin>>N;
  }
  return 0;
}