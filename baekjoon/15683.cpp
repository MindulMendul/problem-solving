#include <iostream>
#include <vector>

#define INF 2100000000

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> cctv; // 종류, y, x
vector<int> cmd;

void copy(vector<vector<int>>& a, vector<vector<int>>& b){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      b[i][j]=a[i][j];
    }
  }
}

void watch(vector<vector<int>>& f, int x, int y, int d){
  int i=0;
  switch(d){
    case 0: // right
      while(x+i<M){
        if(f[y][x+i]==6) break;
        if(f[y][x+i]==0) f[y][x+i]=7;
        i++;
      }
      break;
    case 1: // up
      while(y+i>=0){
        if(f[y+i][x]==6) break;
        if(f[y+i][x]==0) f[y+i][x]=7;
        i--;
      }
      break;
    case 2: // left
      while(x+i>=0){
        if(f[y][x+i]==6) break;
        if(f[y][x+i]==0) f[y][x+i]=7;
        i--;
      }
      break;
    case 3: // down
      while(y+i<N){
        if(f[y+i][x]==6) break;
        if(f[y+i][x]==0) f[y+i][x]=7;
        i++;
      }
      break;
  }
}

void runCCTV(vector<vector<int>>& f, int x, int y, int d, int kind){
  switch(kind){
    case 1:
      watch(f,x,y,d);
      break;
    case 2:
      watch(f,x,y,d);
      watch(f,x,y,(d+2)%4);
      break;
    case 3:
      watch(f,x,y,d);
      watch(f,x,y,(d+1)%4);
      break;
    case 4:
      watch(f,x,y,d);
      watch(f,x,y,(d+1)%4);
      watch(f,x,y,(d+3)%4);
      break;
    case 5:
      watch(f,x,y,d);
      watch(f,x,y,(d+1)%4);
      watch(f,x,y,(d+2)%4);
      watch(f,x,y,(d+3)%4);
      break;
  }
}

int getScore(vector<vector<int>>& f){
  int res=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(f[i][j]==0) res++;
    }
  }
  return res;
}

int dfs(vector<vector<int>>& field, vector<vector<int>>& ff, int dep){
  if(dep==cctv.size()) {
    copy(field, ff);
    for(int i=0; i<cmd.size(); i++){
      runCCTV(ff, cctv[i].second.second, cctv[i].second.first, cmd[i], cctv[i].first);
    }
    return getScore(ff);
  }

  int res=INF;
  for(int d=0; d<4; d++){
    cmd.push_back(d);
    int dd=dfs(field, ff, dep+1);
    cmd.pop_back();
    if(res>dd) res=dd;
  }

  return res;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  vector<vector<int>> field(N, vector<int>(M, 0));
  vector<vector<int>> ff(N, vector<int>(M));
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
    cin>>field[i][j];
    if(field[i][j]>0 && field[i][j]<6){
      cctv.push_back(make_pair(field[i][j], make_pair(i, j)));
    }
  }
  cout<<dfs(field, ff, 0);

  return 0;
}
