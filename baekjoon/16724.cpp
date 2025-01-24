// 맵을 모두 돌아서 회전하는 곳만 찾으면 끝.
// 예외를 착각했다..!!
// => 새로 뻗어나가는 가지가 이미 있던 사이클에 들어가는 경우는?
// 이 경우에는 굳이 그 가지가 사이클에 포함될 이유가 X

#include <iostream>
#include <vector>

using namespace std;

// 0:R 1:U 2:L 3:D
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int getDir(char d){
  if(d=='R') return 0;
  if(d=='D') return 1;
  if(d=='L') return 2;
  if(d=='U') return 3;
  return 0;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, M; cin>>N>>M;
  vector<vector<char>> field(N, vector<char>(M));
  vector<vector<int>> visited(N, vector<int>(M, 0));
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>field[i][j];
    }
  }

  int ans=0, cnt=0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(visited[i][j]>0) continue;
      // 지도밖으로 나가는 입력은 주어지지 않음.
      cnt++;
      int x=j, y=i;
      while(visited[y][x]==0){
        int d=getDir(field[y][x]);
        visited[y][x]=cnt;
        x+=dx[d]; y+=dy[d];
      }
      if(visited[y][x]==cnt){ans++;}
    }
  }
  cout<<ans;

  return 0;
}
