#include <iostream>
#include <vector>

using namespace std;

int dx[9]={-1,0,1,-1,0,1,-1,0,1};
int dy[9]={1,1,1,0,0,0,-1,-1,-1};
int R,C;
int x, y;

int manhattan(int r1, int s1, int r2, int s2){
  int r=r1-r2; if(r<0) r*=-1;
  int s=s1-s2; if(s<0) s*=-1;
  return r+s;
}

int moveRobot(vector<vector<int>>& field, int x, int y, pair<int, int> robot){
  int m=1000000, dir=0;
  for(int d=0; d<9; d++){
    if(d==4) continue;
    int rx=robot.first+dx[d];
    int ry=robot.second+dy[d];
    int tmp_m=manhattan(x,y,rx,ry);
    if (m>tmp_m) {m=tmp_m; dir=d;}
  }
  return dir;
}

int transfer(char c){
  if(c=='I') return 1;
  if(c=='R') return 2;
  return 0;
}

void initField(vector<vector<int>>& field){
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      field[i][j]=0;
    }
  }
}

void printField(vector<vector<int>>& field){
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      switch(field[i][j]){
        case 1: cout<<'I'; break;
        case 2: cout<<'R'; break;
        default: cout<<'.'; break;
      }
    }cout<<'\n';
  }
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>R>>C;
  vector<vector<int>> field(R, vector<int>(C,0));
  vector<vector<int>> ff(R, vector<int>(C,0));
  vector<pair<int, int>> robot;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      char tmp; cin>>tmp;
      field[i][j]=transfer(tmp);
      if(field[i][j]==1) {x=j; y=i;}
      else if(field[i][j]==2) {
        robot.push_back(make_pair(j, i));
      }
    }
  }
  vector<pair<int, int>> robot_next(robot.size());

  int cnt=0;
  string CMD; cin>>CMD;
  for(char c_cmd:CMD){
    // 1, 2 단계 : 종수 아두이노가 움직임
    cnt++;
    int cmd=c_cmd-'1';
    int xx=x+dx[cmd], yy=y+dy[cmd];
    if(field[yy][xx]==2) {
      cout<<"kraj "<<cnt;
      return 0;
    }
    field[y][x]=0; field[yy][xx]=1;
    x=xx; y=yy;
    initField(ff);

    // 3, 4, 5 단계 : 미친 아두이노가 움직임
    // 일단 ff에서 미친 아두이노가 움직일 공간을 미리 계산해두기
    // 이후에 ff를 바탕으로 field 연산해주기.
    for(int i=0; i<robot.size(); i++){
      pair<int, int> r=robot[i];
      if(r.first<0) continue;
      int dir=moveRobot(field,x,y,r);
      int rx=r.first+dx[dir], ry=r.second+dy[dir];
      if(field[ry][rx]==1){
        cout<<"kraj "<<cnt;
        return 0;
      }
      field[r.second][r.first]=0;
      ff[ry][rx]++;
      robot_next[i]=make_pair(rx, ry);
    }

    // ff에서 계산한 걸 field로 옮기는 작업
    for(int i=0; i<robot.size(); i++){
      pair<int, int> r=robot_next[i];
      if(r.first<0) continue;

      // 나만 갈 떄
      if(ff[r.second][r.first]==1){
        field[r.second][r.first]=2;
        robot[i]=make_pair(r.first, r.second);
      }
      else if(ff[r.second][r.first]>1){
        robot[i]=make_pair(-100, -100);
        robot_next[i]=make_pair(-100, -100);
      }
    }
  }

  printField(field);
  return 0;
}
