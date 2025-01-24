#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int field[100][100];
int melt[100][100];
int air[100][100];

bool exists(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(field[i][j]) return true;
    }
  }
  return false;
}

void bfsAir(int x, int y){
  queue<pair<int, int>> q;
  q.push(make_pair(x,y));
  air[y][x]=1;
  while(!q.empty()){
    pair<int, int> t=q.front(); q.pop();
    for(int d=0; d<4; d++){
      int xx=t.first+dx[d], yy=t.second+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      if(field[yy][xx]) continue;
      if(air[yy][xx]) continue;
      air[yy][xx]=1;
      q.push(make_pair(xx,yy));
    }
  }
}

void findOuterAir(){
  for(int i=0; i<N; i++){
    if(!field[i][0]){bfsAir(0,i); break;}
  }
  for(int i=0; i<N; i++){
    if(!field[i][M-1]){bfsAir(M-1,i); break;}
  }
  for(int i=0; i<M; i++){
    if(!field[0][i]){bfsAir(i,0); break;}
  }
  for(int i=0; i<M; i++){
    if(!field[N-1][i]){bfsAir(i,N-1); break;}
  }
}

void melting(int x, int y){
  int cnt=0;
  for(int d=0; d<4; d++){
    int xx=x+dx[d], yy=y+dy[d];
    if(xx<0 || xx>=M || yy<0 || yy>=N) {cnt++; continue;}
    if(air[yy][xx]) {cnt++; continue;}
  }

  melt[y][x]=(cnt>=2);
}

void melton(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      melting(j,i);
    }
  }
}

void meltdown(){
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      air[i][j]=0;
      if(!melt[i][j]) continue;
      melt[i][j]=0;
      field[i][j]=0;
    }
  }
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin>>field[i][j];
      melt[i][j]=0;
    }
  }
  
  int ans=0;
  while(exists()){
    findOuterAir();
    melton();
    meltdown();
    ans++;
  }
  cout<<ans;

  return 0;
}