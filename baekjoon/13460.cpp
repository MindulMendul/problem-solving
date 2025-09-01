#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> pp;

#define MAX 10000

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int N, M;
char map[10][10];
int dp[10][10][10][10];
pair<int, int> red, blue;

pp make_pp(int rx, int ry, int bx, int by){
  return make_pair(make_pair(rx, ry), make_pair(bx, by));
}

// 1. 빨강, 파랑 중에 뭐가 먼저 가야하는지 확인
// 2. 빨강이라 가정, 이동함
// 3. 도착한 곳이
//   a- O면 사라짐
//   b- 파랑이거나 #면 그 전 위치에서 멈춤
// 4. 파랑이 이동함 이동함
// 5. 도착한 곳이
//   a- O면 사라짐
//   b- 빨강이거나 #면 그 전 위치에서 멈춤
// 6. 해당 위치에 dp를 기록

pp move_red_first(int d, pair<int, int> r, pair<int, int> b){
  pair<int, int> sr=r, sb=b;
  int xx=r.first, yy=r.second;
  while(map[yy+dy[d]][xx+dx[d]]=='.' && !(yy+dy[d]==b.second && xx+dx[d]==b.first)){xx+=dx[d]; yy+=dy[d];}
  if(map[yy+dy[d]][xx+dx[d]]=='O'){r.first=-1; r.second=-1;}
  else {r.first=xx; r.second=yy;}

  xx=b.first; yy=b.second;
  while(map[yy+dy[d]][xx+dx[d]]=='.' && !(yy+dy[d]==r.second && xx+dx[d]==r.first)){xx+=dx[d]; yy+=dy[d];}
  if(map[yy+dy[d]][xx+dx[d]]=='O') return make_pair(r, make_pair(-1, -1));
  else {b.first=xx; b.second=yy;}

  
  return make_pair(r, b);
}

pp move_blue_first(int d, pair<int, int> r, pair<int, int> b){
  pair<int, int> sr=r, sb=b;
  int xx=b.first, yy=b.second;
  while(map[yy+dy[d]][xx+dx[d]]=='.' && !(yy+dy[d]==r.second && xx+dx[d]==r.first)){xx+=dx[d]; yy+=dy[d];}
  if(map[yy+dy[d]][xx+dx[d]]=='O') return make_pair(r, make_pair(-1, -1));
  else {b.first=xx; b.second=yy;}

  xx=r.first; yy=r.second;
  while(map[yy+dy[d]][xx+dx[d]]=='.' && !(yy+dy[d]==b.second && xx+dx[d]==b.first)){xx+=dx[d]; yy+=dy[d];}
  if(map[yy+dy[d]][xx+dx[d]]=='O'){r.first=-1; r.second=-1;}
  else {r.first=xx; r.second=yy;}

  return make_pair(r, b);
}

pp move(int d, pair<int, int> r, pair<int, int> b){
  if(d==0) {
    if(r.first>b.first) return move_red_first(d, r, b);
    else return move_blue_first(d, r, b);
  }
  else if(d==1) {
    if(r.second<b.second) return move_red_first(d, r, b);
    else return move_blue_first(d, r, b);
  }
  else if(d==2) {
    if(r.first<b.first) return move_red_first(d, r, b);
    else return move_blue_first(d, r, b);
  }
  else {
    if(r.second>b.second) return move_red_first(d, r, b);
    else return move_blue_first(d, r, b);
  }
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>map[i][j];
      if(map[i][j]=='B') {map[i][j]='.'; blue.first=j; blue.second=i;}
      else if(map[i][j]=='R') {map[i][j]='.'; red.first=j; red.second=i;}

      for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
          dp[i][j][y][x]=MAX;
        }
      }
    }
  }
  
  queue<pp> q;
  q.push(make_pp(red.first, red.second, blue.first, blue.second));
  dp[red.second][red.first][blue.second][blue.first]=0;
  while(!q.empty()){
    pair<int, int> r=q.front().first;
    pair<int, int> b=q.front().second;
    //cout<<r.first<<" "<<r.second<<"/ "<<b.first<<" "<<b.second<<endl;
    q.pop();
    for(int d=0; d<4; d++){
      pp pp_tmp=move(d,r,b);
      pair<int, int> p_red=pp_tmp.first;
      pair<int, int> p_blue=pp_tmp.second;
      if(p_blue.first==-1 && p_blue.second==-1) continue;
      if(dp[r.second][r.first][b.second][b.first]>=10) continue;
      if(p_red.first==-1 && p_red.second==-1) {cout<<dp[r.second][r.first][b.second][b.first]+1; return 0;}
      
      //cout<<d<<": "<<p_red.first<<" "<<p_red.second<<" / "<<p_blue.first<<" "<<p_blue.second<<endl;
      if(dp[p_red.second][p_red.first][p_blue.second][p_blue.first]>dp[r.second][r.first][b.second][b.first]+1){
        dp[p_red.second][p_red.first][p_blue.second][p_blue.first]=dp[r.second][r.first][b.second][b.first]+1;
        q.push(pp_tmp);
      }
    }
  }

  cout<<-1;
  return 0;
}