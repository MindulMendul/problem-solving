#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 2100000000

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int fired[1000][1000];
bool visited[1000][1000];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int TC; cin>>TC;
  for(int tc=1; tc<=TC; tc++){
    int w, h; cin>>w>>h;
    queue<pair<int, int>> q_fire;
    queue<pair<pair<int, int>, int>> q_man;

    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        char map; cin>>map;
        if(map=='@') {fired[i][j]=MAX; q_man.push(make_pair(make_pair(j,i),0)); visited[i][j]=true;}
        else if(map=='#') {fired[i][j]=0; visited[i][j]=true;}
        else if(map=='*') {fired[i][j]=0; q_fire.push(make_pair(j,i)); visited[i][j]=true;}
        else {fired[i][j]=MAX; visited[i][j]=false;}
      }
    }

    while(!q_fire.empty()){
      int x=q_fire.front().first, y=q_fire.front().second;
      q_fire.pop();
      
      for(int d=0; d<4; d++){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=w || yy<0 || yy>=h) continue;
        if(fired[yy][xx] != MAX) continue;
        fired[yy][xx]=fired[y][x]+1;
        q_fire.push(make_pair(xx, yy));
      }
    }

    int ans=MAX;
    while(!q_man.empty()){
      int x=q_man.front().first.first, y=q_man.front().first.second;
      int turn=q_man.front().second;
      q_man.pop();

      for(int d=0; d<4; d++){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=w || yy<0 || yy>=h) {ans=turn+1; break;}
        if(visited[yy][xx]) continue;
        if(fired[yy][xx]<=turn+1) continue;
        visited[yy][xx]=true;
        q_man.push(make_pair(make_pair(xx, yy), turn+1));
      }

      if(ans!=MAX) break;
    }

    if(ans==MAX) cout<<"IMPOSSIBLE";
    else cout<<ans;
    cout<<'\n';
  }

  return 0;
}
