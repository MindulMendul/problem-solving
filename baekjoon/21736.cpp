#include <iostream>
#include <queue>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  //init
  int N, M; cin>>N>>M;
  char map[N][M];
  bool visited[N][M];
  pair<int, int> doyeon;
  for(int i=0; i<N; i++){
    string in; cin>>in;
    for(int j=0; j<M; j++){
      map[i][j]=in[j];
      visited[i][j]=false;
      if(map[i][j]=='I') {
        doyeon=make_pair(i,j);
        visited[i][j]=true;
      }
    }
  }

  //calculate
  int ans=0;
  queue<pair<int, int>> q;
  q.push(doyeon);
  while(!q.empty()){
    pair<int, int> loc=q.front(); q.pop();
    int i=loc.first, j=loc.second;
    for(int d=0; d<4; d++){
      int x=i+dx[d], y=j+dy[d];
      if(x<0 || x>=N || y<0 || y>=M) continue;
      if(map[x][y]=='X') continue;
      if(visited[x][y]) continue;
      visited[x][y]=true;
      if(map[x][y]=='P') ans++;
      q.push(make_pair(x,y));
    }
  }

  if(ans>0) cout<<ans; else cout<<"TT";

  return 0;
}
