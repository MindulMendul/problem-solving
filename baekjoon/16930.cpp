#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int N, M, K;
char map[1000][1000];
int dp[1000][1000];

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M>>K;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>map[i][j];
      dp[i][j]=MAX;
    }
  }
  int sx, sy, ex, ey;
  cin>>sy>>sx>>ey>>ex;
  sx--; sy--; ex--; ey--;
  queue<pair<int, int>> q;
  q.push(make_pair(sx,sy));
  dp[sy][sx]=0;
  if(sx==ex && sy==ey) {cout<<dp[sy][sx]; return 0;}
  while(!q.empty()){
    int x=q.front().first, y=q.front().second; q.pop();
    for(int d=0; d<4; d++){
      int xx=x, yy=y;
      for(int i=1; i<=K; i++){
        xx+=dx[d]; yy+=dy[d];
        if(xx<0 || xx>=M || yy<0 || yy>=N) break;
        if(map[yy][xx]=='#') break;
        if(dp[yy][xx]<dp[y][x]+1) break; // 이 조건이 조금 특이하다...??
        if(dp[yy][xx]==dp[y][x]+1) continue;
        dp[yy][xx]=dp[y][x]+1;
        if(xx==ex && yy==ey) {cout<<dp[yy][xx]; return 0;}
        q.push(make_pair(xx,yy));
      }
    }
  }

  cout<<-1;
  return 0;
}