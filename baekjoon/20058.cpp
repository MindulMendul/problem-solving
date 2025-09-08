#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bin[7]={1,2,4,8,16,32,64};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int N, Q;
int map[64][64];
int copy_map[64][64];

void print_map(){
  for(int i=0; i<bin[N]; i++){
    for(int j=0; j<bin[N]; j++){
      cout<<map[i][j]<<" ";
    }cout<<endl;
  }cout<<endl;
}

void print_copy_map(){
  for(int i=0; i<bin[N]; i++){
    for(int j=0; j<bin[N]; j++){
      cout<<copy_map[i][j]<<" ";
    }cout<<endl;
  }cout<<endl;
}

void tornado(int x, int y, int L){
  for(int i=0; i<bin[L]; i++){
    for(int j=0; j<bin[L]; j++){
      copy_map[i+y][j+x]=map[bin[L]-1-j+y][i+x];
    }
  }
}

void fire(int x, int y){
  if(map[y][x]==0) return;
  int cnt=0;
  for(int d=0; d<4; d++){
    int xx=x+dx[d], yy=y+dy[d];
    if(xx<0 || xx>=bin[N] || yy<0 || yy>=bin[N]) continue;
    if(map[yy][xx]>0) cnt++;
  }

  if(cnt<3) copy_map[y][x]--;
}

void fire_tornado(int L){
  //print_map();
  for(int i=0; i<bin[N]; i+=bin[L]){
    for(int j=0; j<bin[N]; j+=bin[L]){
      tornado(j,i,L);
    }
  }
  for(int i=0; i<bin[N]; i++){
    for(int j=0; j<bin[N]; j++){
      map[i][j]=copy_map[i][j];
    }
  }
  //print_copy_map();
  for(int i=0; i<bin[N]; i++){
    for(int j=0; j<bin[N]; j++){
      fire(j,i);
    }
  }

  for(int i=0; i<bin[N]; i++){
    for(int j=0; j<bin[N]; j++){
      map[i][j]=copy_map[i][j];
    }
  }
  //print_map();
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>Q;
  for(int i=0; i<bin[N]; i++) {
    for(int j=0; j<bin[N]; j++) {
      cin>>map[i][j];
    }
  }

  for(int q=1; q<=Q; q++){
    int L; cin>>L;
    fire_tornado(L);
  }

  int ans1=0, ans2=0;
  for(int i=0; i<bin[N]; i++) for(int j=0; j<bin[N]; j++) {ans1+=map[i][j]; copy_map[i][j]=0;}
  cout<<ans1<<'\n';

  for(int i=0; i<bin[N]; i++) for(int j=0; j<bin[N]; j++){
    if(copy_map[i][j]) continue;
    if(map[i][j]==0) continue;
    int _size=1;
    copy_map[i][j]=1;
    queue<pair<int, int>> q;
    q.push(make_pair(j,i));
    while(!q.empty()){
      int x=q.front().first, y=q.front().second;
      q.pop();
      for(int d=0; d<4; d++){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=bin[N] || yy<0 || yy>=bin[N]) continue;
        if(copy_map[yy][xx]) continue;
        if(map[yy][xx]==0) continue;
        copy_map[yy][xx]=1;
        _size++;
        q.push(make_pair(xx,yy));
      }
    }

    if(_size>ans2) ans2=_size;
  }
  cout<<ans2;

  return 0;
}
