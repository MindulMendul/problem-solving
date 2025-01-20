#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N, M;
int field[1000][1000];
int score[1000][1000];

vector<int> dict_score;

void bfs(int x, int y){
  if(field[y][x]==1) return;
  if(score[y][x]>0) return;

  int res=0, ind=dict_score.size();
  queue<pair<int, int>> q;
  score[y][x]=ind; res++;
  q.push(make_pair(x,y));
  while(!q.empty()){
    int tx=q.front().first, ty=q.front().second; q.pop();
    for(int d=0; d<4; d++){
      int xx=tx+dx[d], yy=ty+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      if(field[yy][xx]==1) continue;
      if(score[yy][xx]>0) continue;
      score[yy][xx]=ind; res++;
      q.push(make_pair(xx,yy));
    }
  }

  dict_score.push_back(res);
}

int main(){
	freopen("input.txt", "rt", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dict_score.push_back(0);
  vector<pair<int, int>> v;
  cin>>N>>M;

  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<M; j++){
      field[i][j]=str[j]-'0';
      score[i][j]=0;
      if(field[i][j]==1){
        v.push_back(make_pair(i, j));
      }
    }
  }

  for(int i=0; i<N; i++) for(int j=0; j<M; j++) bfs(j,i);

  for(auto e: v){
    int ex=e.second, ey=e.first, ans=1;
    unordered_set<int> set_ans;
    for(int d=0; d<4; d++){
      int xx=ex+dx[d], yy=ey+dy[d];
      if(xx<0 || xx>=M || yy<0 || yy>=N) continue;
      set_ans.insert(score[yy][xx]);
    }

    for(auto s:set_ans) ans+=dict_score[s];
    field[ey][ex]=ans;
  }

  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cout<<(field[i][j]%10);
    }
    cout<<'\n';
  }

  return 0;
}