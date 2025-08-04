#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, remained_tomato;
int tomato[1000][1000];
queue<pair<int, int>> vec;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
  

int remain_tomato(){
  int res=0;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(tomato[i][j]==0) res++;
  return res;
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>M>>N;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
    cin>>tomato[i][j];
  }

  remained_tomato=remain_tomato();
  if(remained_tomato==0) {cout<<0; return 0;}
  int ans=0;
  for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(tomato[i][j]==1) vec.push(make_pair(i,j));

  while(1){
    int _size=vec.size();
    if(_size==0) break;
    for(int i=0; i<_size; i++){
      int y=vec.front().first, x=vec.front().second;
      vec.pop();
      for(int d=0; d<4; d++){
        int xx=x+dx[d], yy=y+dy[d];
        if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
        if(tomato[yy][xx]!=0) continue;
        
        vec.push(make_pair(yy,xx));
        tomato[yy][xx]=1;
        
      }
    }
    ans++;
  }

  if(remain_tomato()>0) cout<<-1;
  else cout<<ans-1;

  return 0;
}
