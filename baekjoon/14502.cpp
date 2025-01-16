#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int field[8][8];
int predict[8][8];
vector<pair<int, int>> virus;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void init(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      predict[i][j]=field[i][j];
    }
  }
}

int getScore(){
  int score=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(predict[i][j]==0) score++;
    }
  }

  return score;
}

int bfs(){
  queue<pair<int, int>> q;
  for(auto v:virus){
    q.push(v);
  }
  
  while(!q.empty()){
    pair<int, int> t=q.front(); q.pop();
    predict[t.first][t.second]=2;
    for(int d=0; d<4; d++){
      int xx=t.second+dx[d], yy=t.first+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      if(predict[yy][xx]>0) continue;
      q.push(make_pair(yy,xx));
    }
  }

  return getScore();
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  cin>>N>>M;
	for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>field[i][j];
      if(field[i][j]==2){
        virus.push_back(make_pair(i, j));
      }
    }
  }

  int ans=0;
  for(int i=0; i<N*M; i++){
    for(int j=i+1; j<N*M; j++){
      for(int k=j+1; k<N*M; k++){
        int ix=i%M, iy=i/M; if(field[iy][ix]>0) continue;
        int jx=j%M, jy=j/M; if(field[jy][jx]>0) continue;
        int kx=k%M, ky=k/M; if(field[ky][kx]>0) continue;
        init();
        predict[iy][ix]=1;
        predict[jy][jx]=1;
        predict[ky][kx]=1;

        int res=bfs();
        if(ans<res) ans=res;
      }
    }
  }
  
  cout<<ans;

  return 0;
}
