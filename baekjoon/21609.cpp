#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<pair<int, int>, pair<int, int>> pp;

int N, M;
int map[20][20];
int visited[20][20];
int ss_col, _size, rainbow, min_x, min_y;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void init(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      visited[i][j]=0;
    }
  }
}

void print(){
  cout<<endl;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(map[i][j]>-1) cout<<map[i][j]<<"  ";
      else if(map[i][j]==-1) cout<<"ㅁ  ";
      else if(map[i][j]==-2) cout<<"   ";
    }cout<<endl;
  }
}

// _size rainbow y x
pp find_pos(int px, int py){
  pair<int, int> ss=make_pair(1, 0);
  pair<int, int> pos=make_pair(px, py);
  queue<pair<int, int>> q;
  int col=map[py][px];
  q.push(make_pair(px, py));
  visited[py][px]=col;

  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    
    for(int d=0; d<4; d++){
      int xx=x+dx[d], yy=y+dy[d];
      if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
      if(visited[yy][xx]==col) continue;
      if(map[yy][xx]>0 && map[yy][xx]!=col) continue;
      if(map[yy][xx]<0) continue;
      ss.first++;
      q.push(make_pair(xx,yy));
      visited[yy][xx]=col;
      if(map[yy][xx]==0) {ss.second++; continue;}
      if(yy<pos.second) {pos.first=xx; pos.second=yy;}
      if(yy==pos.second && xx<pos.first) {pos.first=xx; pos.second=yy;}
    }
  }
  return make_pair(ss, pos);
}

bool cmp(pp sspos){
  pair<int, int> ss=sspos.first, pos=sspos.second;
  if(ss.first<2) return false;
  if(ss.first>_size) {
    _size=ss.first; rainbow=ss.second;
    min_x=pos.first; min_y=pos.second;
    return true;
  } else if(ss.first<_size) return false;
  if(ss.second>rainbow){
    rainbow=ss.second;
    min_x=pos.first; min_y=pos.second;
    return true;
  } else if(ss.second<rainbow) return false;
  if(pos.second>min_y){
    min_x=pos.first; min_y=pos.second;
    return true;
  } else if(pos.second<min_y) return false;
  if(pos.first>min_x){
    min_x=pos.first; return true;
  } return false;
}

void find(){
  ss_col=0; _size=0; rainbow=0; min_x=0; min_y=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(map[i][j]<=0) continue;
      if(visited[i][j]) continue;
      bool flag=cmp(find_pos(j,i));
      if(flag) ss_col=map[i][j];
    }
  }
  if(_size<2) _size=-1;
}

void erase(){
  queue<pair<int, int>> q;
  map[min_y][min_x]=-2;
  visited[min_y][min_x]=M+1;
  q.push(make_pair(min_x, min_y));
  while(!q.empty()){
    int x=q.front().first, y=q.front().second;
    q.pop();
    for(int d=0; d<4; d++){
      int xx=x+dx[d], yy=y+dy[d];
      if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
      if(map[yy][xx]<0) continue;
      if(map[yy][xx]>0 && map[yy][xx]!=ss_col) continue;
      if(visited[yy][xx]==M+1) continue;
      map[yy][xx]=-2;
      visited[yy][xx]=M+1;
      q.push(make_pair(xx,yy));
    }
  }
}

void rotate(){
  int tmp_map[N][N];
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) tmp_map[N-j-1][i]=map[i][j];
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) map[i][j]=tmp_map[i][j];
}

void fall(){
  for(int i=0; i<N; i++){
    int ind=N, bot=N-1;
    while(--ind>=0){
      if(map[ind][i]==-2) {continue;}
      if(map[ind][i]==-1) {bot=ind-1; continue;}
      int tmp=map[bot][i];
      map[bot][i]=map[ind][i];
      map[ind][i]=tmp;
      bot--;
    }
  }
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>N>>M;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>>map[i][j];
    }
  }
  
  int ans=0;
  while(true){
    init();
    find();
    if(_size==-1) break;
    erase();
    ans+=_size*_size;
    fall();
    rotate();
    fall();
  }
  cout<<ans;

  return 0;
}