/// dp+bfs 방식으로 풂.
/// 신기한 건, 위상정렬로 문제를 푸는 방식...!

// 32 20 17 
// 30 25

// 위와 같은 예시가 있다면
// 32 -> 20 -> 17
// 32 -> (30 -> 25) -> 20 -> 17
// 이렇게 동선이 두 개가 있을 것이다.

// 높이 기준으로 위상정렬을 도입한 것이기 때문에,
// 반드시 저 괄호부분이 먼저 연산이 된 뒤에 20이 연산이 된다!
// 따라서 첫 방문 때만 큐에 넣는 것은
// 20에 dp 값을 처음으로 넣어주고 17이 큐에 push되더라도,
// 30->25 가 20 -> 17 가는 것보다 무조건 먼저 연산되기 때문에
// 30->25 가던 추가경로를 20에 챙겨준 뒤에야 17로 이동할 수 있도록 해준다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int map[500][500];
int dp[500][500];
int M, N;


struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return map[a.first][a.second]<map[b.first][b.second];
  }
};

void init(){
  cin>>M>>N;
  for(int i=0; i<M; i++) for(int j=0; j<N; j++) cin>>map[i][j];
  for(int i=0; i<M; i++) for(int j=0; j<N; j++) dp[i][j]=0;
}

int main(){
  freopen("input.txt", "rt", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();
  dp[0][0]=1;

  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
  pq.push(make_pair(0, 0));
  while(!pq.empty()){
    int y=pq.top().first, x=pq.top().second; pq.pop();
    for(int d=0; d<4; d++){
      int yy=y+dy[d], xx=x+dx[d];
      if(yy<0 || yy>=M || xx<0 || xx>=N) continue;
      if(map[y][x]<=map[yy][xx]) continue;

      if(dp[yy][xx]==0) pq.push(make_pair(yy,xx));
      dp[yy][xx]+=dp[y][x];
    }
  }

  cout<<dp[M-1][N-1];

  return 0;
}
